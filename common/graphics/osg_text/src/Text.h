/*
 *  Copyright 2014, DFKI GmbH Robotics Innovation Center
 *
 *  This file is part of the MARS simulation framework.
 *
 *  MARS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3
 *  of the License, or (at your option) any later version.
 *
 *  MARS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with MARS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * \file Text.h
 * \author Malte Langosz
 * \brief This library wraps the osgText lib and adds the possiblity to
 *        use an background color and border for text labels.
 **/

#ifndef OSG_TEXT_H
#define OSG_TEXT_H

#ifdef _PRINT_HEADER_
#warning "Text.h"
#endif

#include "TextInterface.h"

#include <osg/MatrixTransform>
#include <osg/Geometry>
#include <osgText/Text>

#include <string>

namespace osg_text {

  class Text : public TextInterface, public osg::Group {

  public:
    Text(std::string text="", double fontSize=12, Color textColor=Color(),
         double posX=0., double posY=0., TextAlign textAlign=ALIGN_LEFT,
         double paddingL=0., double paddingT=0.,
         double paddingR=0., double paddingB=0.,         
         Color backgroundColor=Color(),
         Color borderColor=Color(),
         double borderWidth = 0.0, std::string fontPath="");

    ~Text();
    void setText(const std::string &s);
    void setFontSize(const double fontSize);
    void setBackgroundColor(const Color &c);
    void setBorderColor(const Color &c);
    void setBorderWidth(double w);
    void setPadding(double left, double top, double right, double bottom);
    void* getOSGNode();
    void setFixedWidth(double w);
    void setFixedHeight(double h);
    void setPosition(double x, double y);
    void setFontResolution(int x, int y);
    void getRectangle(double *left, double *right,
                      double *top, double *bottom);
    void getPosition(double *x, double *y);
    std::string getText();
    double getFontsize();
    void getPadding(double *pl, double *pt, double *pr, double *pb);
    TextAlign getAlign();
    Color getBackgroundColor();
    Color getBorderColor();
    double getBorderWidth();
    std::string getFont();

  private:
    osg::ref_ptr<osg::PositionAttitudeTransform> transform;
    osg::ref_ptr<osgText::Text> labelText;
    osg::ref_ptr<osg::Geode> labelGeode;
    osg::ref_ptr<osg::Geode> backgroundGeode;
    osg::ref_ptr<osg::Geode> borderGeode;
    osg::ref_ptr<osg::Geometry> backgroundGeom;
    osg::ref_ptr<osg::Geometry> borderGeom;
    osg::ref_ptr<osg::Vec3Array> backgroundVertices;
    osg::ref_ptr<osg::Vec3Array> borderVertices;
    osg::ref_ptr<osg::MatrixTransform> resolutionCorrection;

    double width, height;
    double posX, posXI, posY;
    TextAlign textAlign;
    double pl, pt, pr, pb;
    double fixedWidth, fixedHeight, w, h, posXB;
    double fontSize;
    osg::ref_ptr<osg::Vec4Array> backgroundColor, borderColor;
    double borderWidth;
    double resolutionCorrectionX, resolutionCorrectionY;
    std::string text_;
    std::string font;

    void updateSize();
    void updateBoundingBox();
    void updatePosition();
    void createBackground(Color bgColor);
    void updateBackgroundPos();
    void createBorder(Color bColor);
    void updateBorderPos();
  };

} // end of namespace: osg_text

#endif // OSG_TEXT_H

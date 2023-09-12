/*
  ==============================================================================

    CustomSliderCollection.cpp
    Created: 23 Aug 2023 12:46:13am
    Author:  MERT KABUKÇUOĞLU

  ==============================================================================
*/

#include "CustomSliderCollection.h"
namespace juce
{
    void CustomDrawnSlider::NeuralDSP_fullArc::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
    {
        //auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        //auto fill    = slider.findColour (Slider::rotarySliderFillColourId);

        auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin (8.0f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;

        Path backgroundArc;
        backgroundArc.addCentredArc (bounds.getCentreX(),
                                     bounds.getCentreY(),
                                     arcRadius,
                                     arcRadius,
                                     0.0f,
                                     rotaryStartAngle,
                                     rotaryEndAngle,
                                     true);

        if (sliderPos == 0)
        {
            g.setColour(juce::Colours::darkgrey);
        }//found when debugging find a better solution
        else
        g.setColour(juce::Colours::grey);
        g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

        if (slider.isEnabled())
        {
            Path valueArc;
            valueArc.addCentredArc (bounds.getCentreX(),
                                    bounds.getCentreY(),
                                    arcRadius,
                                    arcRadius,
                                    0.0f,
                                    rotaryStartAngle,
                                    toAngle,
                                    true);

            g.setColour (juce::Colours::whitesmoke);
            g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }
        
        //custom layout
       Path constantArc;
       constantArc.addCentredArc(bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius- 12.5,
                                arcRadius- 12.5 ,
                                MathConstants<float>::halfPi,
                                0.0f,
                                MathConstants<float>::twoPi,
                                true);
        if(sliderPos == 0)
        {
            g.setColour(juce::Colours::grey);
        }//found when debugging find a better solution
        else
        g.setColour(juce::Colours::white);
        g.strokePath (constantArc, PathStrokeType (lineW / 2.0f, PathStrokeType::curved, PathStrokeType::rounded));
        
       
       //g.drawEllipse(bounds.getCentreX(),bounds.getCentreY(),bounds.getCentreX() + (arcRadius-12),bounds.getCentreY() + (arcRadius-12), 4.0f);
        

        //thumb
        auto thumbWidth = lineW * 1.3F;
        Point<float> thumbPoint (bounds.getCentreX() + (arcRadius-25)  * std::cos (toAngle - MathConstants<float>::halfPi),
                                 bounds.getCentreY() + (arcRadius-25)  * std::sin (toAngle - MathConstants<float>::halfPi));
        if(sliderPos == 0)
        {
            g.setColour(juce::Colours::grey);
        }//found when debugging find a better solution
        else
        g.setColour(juce::Colours::white);
        g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
        //g.drawLine(backgroundArc.getBounds().getCentreX(),backgroundArc.getBounds().getCentreY(),thumbPoint.getX(),thumbPoint.getY(),lineW);
    }

    void CustomDrawnSlider::NeuralDSP_halfArc::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
    {
        auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(10);
        auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin(8.0f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;

        Path backgroundArc;
        backgroundArc.addCentredArc(bounds.getCentreX(),
            bounds.getCentreY(),
            arcRadius,
            arcRadius,
            0.0f,
            rotaryStartAngle,
            rotaryEndAngle,
            true);
            g.setColour(juce::Colours::grey);
            g.strokePath(backgroundArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));

        if (slider.isEnabled())
        {
            Path valueArc;
            valueArc.addCentredArc(bounds.getCentreX(),
                bounds.getCentreY(),
                arcRadius,
                arcRadius,
                0.0f,
                (rotaryStartAngle+rotaryEndAngle)/2,
                toAngle,
                true);
            if (sliderPos == 0.5f) //find a better solution!
            {
                valueArc.clear();
               // g.setColour(juce::Colours::grey);
            }
            else
            {
                g.setColour(juce::Colours::white);
            }
            
            g.strokePath(valueArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }

        //custom layout
        Path constantArc;
        constantArc.addCentredArc(bounds.getCentreX(),
            bounds.getCentreY(),
            arcRadius - 12.5,
            arcRadius - 12.5,
            MathConstants<float>::halfPi,
            0.0f,
            MathConstants<float>::twoPi,
            true);
        g.setColour(juce::Colours::white);
        g.strokePath(constantArc, PathStrokeType(lineW / 2.0f, PathStrokeType::curved, PathStrokeType::rounded));


        //g.drawEllipse(bounds.getCentreX(),bounds.getCentreY(),bounds.getCentreX() + (arcRadius-12),bounds.getCentreY() + (arcRadius-12), 4.0f);


         //thumb
        auto thumbWidth = lineW * 1.3F;
        Point<float> thumbPoint(bounds.getCentreX() + (arcRadius - 25) * std::cos(toAngle - MathConstants<float>::halfPi),
            bounds.getCentreY() + (arcRadius - 25) * std::sin(toAngle - MathConstants<float>::halfPi));
        g.setColour(juce::Colours::white);
        g.fillEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint));
        //g.drawLine(backgroundArc.getBounds().getCentreX(),backgroundArc.getBounds().getCentreY(),thumbPoint.getX(),thumbPoint.getY(),lineW);
    }

void CustomDrawnSlider::svgSlider::drawRotarySlider(Graphics &g , int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider & s)
{
    if (const auto svg = XmlDocument::parse(BinaryData::arrow_svg))
    {
        const auto drawable = Drawable::createFromSVG(*svg);
        drawable->setTransformToFit(Rectangle<int>(x, y, width, height).toFloat(), RectanglePlacement::centred);
            
            //drawable->setColour(int colourID, <#Colour newColour#>)

        const float angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
          drawable->draw(g, 1.f, AffineTransform::rotation(angle, width / 2.f, height / 2.f));
    }
}

void CustomDrawnSlider::pngSlider::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& s)
{
    const double rotation = (s.getValue()  - s.getMinimum()) / (s.getMaximum() - s.getMinimum());
    Image img = ImageCache::getFromMemory(BinaryData::knob_silver_png, BinaryData::knob_silver_pngSize);
    const int frames = img.getHeight() / img.getWidth();
    const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
    const float radius = jmin(width / 2.0f, height / 2.0f);
    const float centerX = x + width * 0.5f;
    const float centerY = y + height * 0.5f;
    const float rx = centerX - radius - 1.0f;
    const float ry = centerY - radius;

    g.drawImage(img,
        (int)rx,
        (int)ry,
        2 * (int)radius,
        2 * (int)radius,
        0,
        frameId * img.getWidth(),
        img.getWidth(),
        img.getWidth());
}

    
}

/*
  ==============================================================================

    CustomSliderCollection.h
    Created: 23 Aug 2023 12:46:13am
    Author:  MERT KABUKÇUOĞLU

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace juce
{

class CustomDrawnSlider 
{
public:
    struct NeuralDSP: public Slider ,public LookAndFeel_V4
    {
       void drawRotarySlider(Graphics&, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider&);
    };
    
};
}

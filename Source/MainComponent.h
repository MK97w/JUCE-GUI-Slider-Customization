#pragma once

#include <JuceHeader.h>
#include "CustomSliderCollection.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    //juce::CustomDrawnSlider m_customDrawnSliderLookAndFeel;
    juce::CustomDrawnSlider::NeuralDSP_fullArc fullArc_Slider;
    juce::CustomDrawnSlider::NeuralDSP_halfArc halfArc_Slider;
    juce::CustomDrawnSlider::svgSlider arrow_Slider;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

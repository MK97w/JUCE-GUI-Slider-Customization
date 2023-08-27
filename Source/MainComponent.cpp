#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //juce::LookAndFeel::setDefaultLookAndFeel(&halfArc_Slider);
    setSize (800, 200);
    
    fullArc_Slider.setLookAndFeel(&fullArc_Slider);
    fullArc_Slider.setRange(0.0f, 10.0f);
    addAndMakeVisible(fullArc_Slider);
    fullArc_Slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    fullArc_Slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 100);

    halfArc_Slider.setLookAndFeel(&halfArc_Slider);
    halfArc_Slider.setRange(0.0f, 5.0f);
    halfArc_Slider.setValue(5.0f/2.0f);
    addAndMakeVisible(halfArc_Slider);
    halfArc_Slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    halfArc_Slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 100);
    
    
    arrow_Slider.setLookAndFeel(&arrow_Slider);
    arrow_Slider.setRange(0.0f, 10.0f);
    addAndMakeVisible(arrow_Slider);
    arrow_Slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    arrow_Slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 100);
    
    

}

MainComponent::~MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
    fullArc_Slider.setLookAndFeel(nullptr);
    halfArc_Slider.setLookAndFeel(nullptr);
    arrow_Slider.setLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::darkkhaki);
    
    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    fullArc_Slider.setBounds(0 , 0 , 200, 200); //when downsized slşder looks awful!
    halfArc_Slider.setBounds(200, 0, 200, 200);
    arrow_Slider.setBounds(400,0, 200, 200);
}


#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(&mySlider);
    setSize (400, 400);
    mySlider.setRange(0.0f, 10.0f);
    addAndMakeVisible(mySlider);
    mySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mySlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 100);
}

MainComponent::~MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
    
    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    mySlider.setBounds(getWidth()/2 -100  , getHeight()/2 - 100 ,200,200);
}


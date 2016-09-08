#ifndef TRACKERSTIMULATORCANVAS_H
#define TRACKERSTIMULATORCANVAS_H

#include "TrackerStimulator.h"
#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Visualization/Visualizer.h"
#include "../Editors/GenericEditor.h"

class DisplayAxes;

class TrackerStimulatorCanvas : public Visualizer,
        public Button::Listener,
        public Label::Listener,
        public KeyListener
//        public ComboBox::Listener,
{
public:
    TrackerStimulatorCanvas(TrackerStimulator* trackerStimulator);
    ~TrackerStimulatorCanvas();

    void paint (Graphics&);
    void resized();
    void clear();
    void initButtons();
    void initLabels();

    TrackerStimulator* getProcessor();

    // KeyListener interface
    virtual bool keyPressed(const KeyPress &key, Component *originatingComponent);

    // Listener interface
    virtual void buttonClicked(Button* button);
    virtual void labelTextChanged(Label *label) override;

    // Visualizer interface
    virtual void refreshState();
    virtual void update();
    virtual void refresh();
    virtual void beginAnimation();
    virtual void endAnimation();
    virtual void setParameter(int, float);
    virtual void setParameter(int, int, int, float);

    bool getUpdateCircle();
    void setUpdateCircle(bool onoff);
    bool areThereCicles();
    void setOnButton();
    float my_round(float x);

    // *** Maybe adjust with proper accessors instead of keep public *** //
    ScopedPointer<UtilityButton> clearButton;
    ScopedPointer<UtilityButton> newButton;
    ScopedPointer<UtilityButton> editButton;
    ScopedPointer<UtilityButton> delButton;
    ScopedPointer<UtilityButton> onButton;
    ScopedPointer<UtilityButton> newcircButton;
    ScopedPointer<UtilityButton> circlesButton[MAX_CIRCLES];
    ScopedPointer<UtilityButton> uniformButton;
    ScopedPointer<UtilityButton> gaussianButton;
    ScopedPointer<UtilityButton> negFirstButton;
    ScopedPointer<UtilityButton> posFirstButton;
    ScopedPointer<UtilityButton> biphasicButton;
    ScopedPointer<UtilityButton> chan1Button;
    ScopedPointer<UtilityButton> chan2Button;
    ScopedPointer<UtilityButton> chan3Button;
    ScopedPointer<UtilityButton> chan4Button;

    // Label with non-editable text
    ScopedPointer<Label> cxLabel;
    ScopedPointer<Label> cyLabel;
    ScopedPointer<Label> cradLabel;
    ScopedPointer<Label> onLabel;
    ScopedPointer<Label> fmaxLabel;
    ScopedPointer<Label> elecLabel;
    ScopedPointer<Label> pulsePalLabel;
    ScopedPointer<Label> pulsePalStatusLabel;
    ScopedPointer<Label> phaseLabel;
    ScopedPointer<Label> interphaseLabel;
    ScopedPointer<Label> voltageLabel;
    ScopedPointer<Label> interpulseLabel;
    ScopedPointer<Label> repetitionsLabel;


    // Labels with editable test
    ScopedPointer<Label> cxEditLabel;
    ScopedPointer<Label> cyEditLabel;
    ScopedPointer<Label> cradEditLabel;
    ScopedPointer<Label> fmaxEditLabel;
    ScopedPointer<Label> elecEditLabel;
    ScopedPointer<Label> phaseEditLabel;
    ScopedPointer<Label> interphaseEditLabel;
    ScopedPointer<Label> voltageEditLabel;
    ScopedPointer<Label> interpulseEditLabel;
    ScopedPointer<Label> repetitionsEditLabel;


private:
    TrackerStimulator* processor;
    float m_x;
    float m_y;
    float m_prevx;
    float m_prevy;
    float m_width;
    float m_height;

    float m_current_cx;
    float m_current_cy;
    float m_current_crad;

    bool m_onoff;
    bool m_updateCircle;

    ScopedPointer<DisplayAxes> m_ax;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackerStimulatorCanvas)
};

///**

//  Class for displaying and draw circles and current position

//*/

class DisplayAxes : public Component
{
public:
    DisplayAxes(TrackerStimulator* trackerStimulator, TrackerStimulatorCanvas* trackerStimulatorCanvas);
    ~DisplayAxes();

    void setXLims(double xmin, double xmax);
    void setYLims(double ymin, double ymax);

    void paint(Graphics& g);

    void clear();

    void mouseMove(const MouseEvent& event);
    void mouseEnter(const MouseEvent& event);
    void mouseExit(const MouseEvent& event);
    void mouseDown(const MouseEvent& event);
    void mouseUp(const MouseEvent& event);
    void mouseDrag(const MouseEvent& event);


private:

    double xlims[2];
    double ylims[2];

    TrackerStimulator* processor;
    TrackerStimulatorCanvas* canvas;

    Colour selectedCircleColour;
    Colour unselectedCircleColour;
    Colour backgroundColour;
    Colour outOfCirclesColour;
    Colour inOfCirclesColour;

    int64 click_time;

    bool m_firstPaint;

    bool m_creatingNewCircle;
    bool m_mayBeMoving;
    bool m_movingCircle;
    bool m_doubleClick;

    float m_newX;
    float m_newY;
    float m_newRad;
    float m_tempRad;

    MouseCursor::StandardCursorType cursorType;

};

#endif // TRACKERSTIMULATORCANVAS_H

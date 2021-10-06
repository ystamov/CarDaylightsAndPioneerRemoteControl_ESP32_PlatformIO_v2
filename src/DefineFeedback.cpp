#include <DefineFeedback.h>
#include <Arduino.h>
#include <GlobalVariables.h>
#include <ESP32_IO.h>
#include <PrintInfo.h>

// Analog feedback thresholds
float srcOffReceivedLowThreshold      = 0.40;
float srcOffReceivedHighThreshold     = 0.6;
float attReceivedLowThreshold         = 0.55;
float attReceivedHighThreshold        = 0.88;
float fileInfoReceivedLowThreshold    = 1.0;
float fileInfoReceivedHighThreshold   = 1.15;
float nextTrackReceivedLowThreshold   = 1.2;
float nextTrackReceivedHighThreshold  = 1.35;
float prevTrackReceivedLowThreshold   = 1.42;
float prevTrackReceivedHighThreshold  = 1.65;
float volumeUpReceivedLowThreshold    = 1.75;
float volumeUpReceivedHighThreshold   = 1.9;
float volumeDownReceivedLowThreshold  = 2;
float volumeDownReceivedHighThreshold = 2.2;
float bandReceivedLowThreshold        = 2.4;
float bandReceivedHighThreshold       = 2.85;

// Feedback command received booleans
bool sourceOffFeedbackReceived                   = false;
bool attFeedbackReceived                         = false;
bool fileInfoFeedbackReceived                    = false;
bool nextTrackTuneUpFeedbackReceived             = false;
bool prevTrackTuneDownFolderDownFeedbackReceived = false;
bool volumeUpFeedbackReceived                    = false;
bool volumeDownFeedbackReceived                  = false;
bool bandFeedbackReceived                        = false;

// Analog feedback variables
float tip3v3FeedbackValue  = 0.0;
float ring3v3FeedbackValue = 0.0;

void DefineFeedback()
{
    tip3v3FeedbackValue = ((float)analogRead(i3v3TipFeedbackVoltage) / adcResolution) * refVoltage;
    ring3v3FeedbackValue = ((float)analogRead(i3v3RingFeedbackVoltage) / adcResolution) * refVoltage;

    sourceOffFeedbackReceived                   = tip3v3FeedbackValue >= srcOffReceivedLowThreshold       && 
                                                  tip3v3FeedbackValue <= srcOffReceivedHighThreshold;   
    attFeedbackReceived                         = tip3v3FeedbackValue >= attReceivedLowThreshold          && 
                                                  tip3v3FeedbackValue <= attReceivedHighThreshold;
    fileInfoFeedbackReceived                    = tip3v3FeedbackValue >= fileInfoReceivedLowThreshold     && 
                                                  tip3v3FeedbackValue <= fileInfoReceivedHighThreshold;
    nextTrackTuneUpFeedbackReceived             = tip3v3FeedbackValue >= nextTrackReceivedLowThreshold    && 
                                                  tip3v3FeedbackValue <= nextTrackReceivedLowThreshold;   
    prevTrackTuneDownFolderDownFeedbackReceived = tip3v3FeedbackValue >= prevTrackReceivedLowThreshold    && 
                                                  tip3v3FeedbackValue <= prevTrackReceivedHighThreshold; 
    volumeUpFeedbackReceived                    = tip3v3FeedbackValue >= volumeUpReceivedLowThreshold     && 
                                                  tip3v3FeedbackValue <= volumeUpReceivedHighThreshold; 
    volumeDownFeedbackReceived                  = tip3v3FeedbackValue >= volumeDownReceivedLowThreshold   && 
                                                  tip3v3FeedbackValue <= volumeDownReceivedHighThreshold; 
    bandFeedbackReceived                        = tip3v3FeedbackValue >= bandReceivedLowThreshold         && 
                                                  tip3v3FeedbackValue <= bandReceivedHighThreshold; 
}
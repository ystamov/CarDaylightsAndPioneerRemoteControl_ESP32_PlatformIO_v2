#ifndef DefineFeedback_h
#define DefineFeedback_h

// Analog feedback thresholds
extern float srcOffReceivedLowThreshold;        
extern float srcOffReceivedHighThreshold;       
extern float attReceivedLowThreshold;           
extern float attReceivedHighThreshold;
extern float fileInfoReceivedLowThreshold;
extern float fileInfoReceivedHighThreshold;    
extern float nextTrackReceivedLowThreshold;     
extern float nextTrackReceivedHighThreshold;    
extern float prevTrackReceivedLowThreshold;     
extern float prevTrackReceivedHighThreshold;    
extern float volumeUpReceivedLowThreshold;      
extern float volumeUpReceivedHighThreshold;     
extern float volumeDownReceivedLowThreshold;    
extern float volumeDownReceivedHighThreshold;   
extern float bandReceivedLowThreshold;          
extern float bandReceivedHighThreshold;  

// Feedback received booleans
extern bool sourceOffFeedbackReceived;                   
extern bool attFeedbackReceived;
extern bool fileInfoFeedbackReceived;                         
extern bool nextTrackTuneUpFeedbackReceived;             
extern bool prevTrackTuneDownFolderDownFeedbackReceived; 
extern bool volumeUpFeedbackReceived;                    
extern bool volumeDownFeedbackReceived;                  
extern bool bandFeedbackReceived; 

// Analog feedback variables
extern float tip3v3FeedbackValue;
extern float ring3v3FeedbackValue;

extern void DefineFeedback();

#endif
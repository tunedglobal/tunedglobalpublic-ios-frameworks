
#if !defined AUTOMIX_SDK_H
#define AUTOMIX_SDK_H

#import <AVFoundation/AVFoundation.h>

#ifdef __cplusplus
#import <string>
extern "C" {
#endif
    void __b_duff_debug(const char* _Nullable message);
    void __b_duff_info(const char* _Nullable message);
    void __b_duff_warn(const char* _Nullable message);
    void __b_duff_error(const char* _Nullable message);
    void __b_duff_fatal(const char* _Nullable message);

    void __b_duff_assert_false(void);

    void __b_duff_debug_break(void);

    void __b_duff_exception_message(const char* _Nullable message);

    NSString* _Nonnull _HMACAlgorithmSign(int algorithmInt, NSString* _Nonnull input, NSString* _Nonnull key);
#ifdef __cplusplus
}
#endif

@protocol AutomixIQStreamingDelegate;
@protocol AutomixIQStatusObserverDelegate;
@protocol AutomixIQTunedRestDelegate;
@protocol SocialRadioUIDelegate;
@protocol SocialRadioBackendDelegate;
@protocol AutomixNetworkObserver;
@protocol AutomixIQTunedMusicCacheDelegate;
@class AutomixIQTrackModel;
@class AutomixIQStatus;
@class AutomixIQWaveformModel;
@class AutomixIQConfig;

typedef void (^CompletionWithError)(NSError* _Nullable error);
typedef void (^CompletionWithErrorAndPlaybackState)(NSError* _Nullable error, AutomixIQStatus* _Nonnull status);

/// AutomixIQObjC represents the AutomixIQ SDK and exposes all its functionality for use in Objective-C classes. It follows a Singleton pattern.
@interface AutomixIQObjC : NSObject

@property (nonatomic, assign) BOOL on;

#ifdef HAVE_AUTOMIXIQ

+(BOOL)initialised;
+(nonnull NSError*)automixIQErrorWithCode:(int)code;
+(nonnull NSString*)errorDescriptionWithCode:(int)code;

+(void)initialiseWithConfig:(nonnull AutomixIQConfig*)config
 automixIQTunedRestDelegate:(nonnull id<AutomixIQTunedRestDelegate>)automixIQTunedRestDelegate
    automixIQStatusDelegate:(nullable id<AutomixIQStatusObserverDelegate>)automixIQStatusDelegate
         musicCacheDelegate:(nullable id<AutomixIQTunedMusicCacheDelegate>)musicCacheDelegate
                 completion:(nullable CompletionWithError)completion;

+(void)initialiseWithConfig:(nonnull AutomixIQConfig*)config
 automixIQStreamingDelegate:(nonnull id<AutomixIQStreamingDelegate>)automixIQStreamingDelegate
    automixIQStatusDelegate:(nullable id<AutomixIQStatusObserverDelegate>)automixIQStatusDelegate
                 completion:(nullable CompletionWithError)completion;

+(BOOL)internetAvailable;
+(nullable instancetype)instance;

-(void)forceRefreshCredentialsWithCompletion:(nullable CompletionWithError)completion;

-(void)clearCacheWithCompletion:(nullable CompletionWithError)completion;

-(void)setMusicCacheDelegate:(nullable id<AutomixIQTunedMusicCacheDelegate>)musicCacheDelegate;
-(void)addStatusObserverDelegate:(nonnull id<AutomixIQStatusObserverDelegate>)statusObserverDelegate;
-(void)removeStatusObserverDelegate:(nonnull id<AutomixIQStatusObserverDelegate>)statusObserverDelegate;

-(nullable UIViewController*)radioUIViewController;
-(void)joinLiveBroadcastWithIdentifier:(nonnull NSString*)identifier
                            completion:(nullable CompletionWithError)completion;

-(void)automixOnWithCompletion:(nullable CompletionWithError)completion;
-(void)automixOnWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                       metadata:(nullable NSArray<AutomixIQTrackModel*>*)trackMetadataArray
                 playTrackIndex:(int)index seconds:(float)seconds autoplay:(BOOL)autoplay
                    contextType:(nullable NSString*)contextType contextId:(nullable NSString*)contextId
                     completion:(nullable CompletionWithError)completion;
-(void)automixOffWithCompletion:(nullable CompletionWithErrorAndPlaybackState)completion;
-(void)resetPlaylistToEmptyWithCompletion:(nullable CompletionWithError)completion;

-(void)loadTracksWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                        metadata:(nullable NSArray<AutomixIQTrackModel*>*)trackMetadataArray
                  playTrackIndex:(int)index seconds:(float)seconds autoplay:(BOOL)autoplay
                     contextType:(nullable NSString*)contextType contextId:(nullable NSString*)contextId
                      completion:(nullable CompletionWithError)completion;
-(void)addTracksWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                       metadata:(nullable NSArray<AutomixIQTrackModel*>*)trackMetadataArray
                          index:(int)index completion:(nullable CompletionWithError)completion;
-(void)addTrackWithIdentifier:(nonnull NSString*)identifier
                     metadata:(nullable AutomixIQTrackModel*)metadata
                        index:(int)index completion:(nullable CompletionWithError)completion;
-(void)removeTrackAtIndex:(int)index completion:(nullable CompletionWithError)completion;
-(void)moveTrackAtIndex:(int)index toIndex:(int)index completion:(nullable CompletionWithError)completion;
-(void)playWithCompletion:(nullable CompletionWithError)completion;
-(void)pauseWithCompletion:(nullable CompletionWithError)completion;
-(void)nextWithCompletion:(nullable CompletionWithError)completion;
-(void)previousWithCompletion:(nullable CompletionWithError)completion;
-(void)backWithCompletion:(nullable CompletionWithError)completion;
-(void)toggleReplayWithCompletion:(nullable CompletionWithError)completion;
-(void)setReplayOn:(BOOL)on completion:(nullable CompletionWithError)completion;
-(void)seekToSeconds:(float)seconds completion:(nullable CompletionWithError)completion;
-(void)skipToTrackAtIndex:(int)index completion:(nullable CompletionWithError)completion;
-(void)setFilterExplicit:(BOOL)filterExplicit completion:(nullable CompletionWithError)completion;
-(void)reorderTracksWithNewOrder:(nonnull NSArray<NSString*>*)newOrder completion:(nullable CompletionWithError)completion;
-(void)playTrackToEndThenPauseWithCompletion:(nullable CompletionWithError)completion;
-(void)setAutomixPlaySpeed:(float)playSpeed completion:(nullable CompletionWithError)completion;
-(void)setAutomixVolumeNormalised:(float)volumeNormalised completion:(nullable CompletionWithError)completion;
-(void)toggleMuteWithCompletion:(nullable CompletionWithError)completion;
-(void)setMuteOn:(BOOL)on completion:(nullable CompletionWithError)completion;
-(void)setPreferredTransitionDurationSeconds:(float)preferredTransitionDurationSeconds completion:(nullable CompletionWithError)completion;
-(void)loopPlayingTrackWithCompletion:(nullable CompletionWithError)completion;
-(void)stopLoopingPlayingTrackWithCompletion:(nullable CompletionWithError)completion;
-(void)setVinylStartStopEnabled:(BOOL)enabled completion:(nullable CompletionWithError)completion;

-(void)stopEngine;
-(void)setRecordingAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer;
-(int)getAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels fadeState:(int)fadeState audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer isRecording:(nonnull BOOL*)isRecording;
-(BOOL)isAudioDeviceActiveOrRecording:(nonnull BOOL*)recording;

-(void)setWaveformPointsPerTrack:(int)waveformPointsPerTrack;
-(nullable AutomixIQWaveformModel*)waveformDataForTrackWithIdentifier:(nonnull NSString*)identifier applyTransitions:(BOOL)applyTransitions;
-(nullable AutomixIQWaveformModel*)waveformDataForTrackWithIdentifier:(nonnull NSString*)identifier applyEnterTransition:(BOOL)applyEnterTransition applyExitTransition:(BOOL)applyExitTransition;
-(nullable AutomixIQWaveformModel*)placeholderWaveformDataForTrackWithIdentifier:(nonnull NSString*)identifier;

-(void)terminate;

-(nonnull id<AutomixIQStreamingDelegate>)getAutomixStreamingDelegate;
-(nullable AutomixIQStatus*)automixStatus;

#ifdef MIXTAPE_REPO_UI
-(nonnull NSString*)mediumFontName;
-(CGFloat)largeFontSize;
#endif

#endif
@end

#endif

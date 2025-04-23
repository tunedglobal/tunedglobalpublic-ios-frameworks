
#if !defined RADIO_SDK_H
#define RADIO_SDK_H

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

@protocol TunedRestDelegate;
@protocol SocialRadioStreamingDelegate;
@protocol SocialBackendDelegate;
@protocol SocialRadioStatusObserverDelegate;
@protocol SocialRadioUIDelegate;
@protocol SocialRadioTunedMusicCacheDelegate;

@class SocialRadioList;
@class TunedTrackModel;
@class SocialRadioConfig;
@protocol AutomixIQStreamingDelegate;
@protocol SocialRadioStreamingDelegate;

@interface SocialRadioObjC : NSObject

+(void)initializeWithConfig:(nonnull SocialRadioConfig*)config
          tunedRestDelegate:(nonnull id<TunedRestDelegate>)tunedRestDelegate
  socialRadioStatusDelegate:(nullable id<SocialRadioStatusObserverDelegate>)socialRadioStatusDelegate
      socialRadioUIDelegate:(nonnull id<SocialRadioUIDelegate>)socialRadioUIDelegate
                 completion:(void (^_Nullable)(NSError* _Nullable error))completion;

+(void)initializeWithConfig:(nonnull SocialRadioConfig*)config
 automixIQStreamingDelegate:(nonnull id<AutomixIQStreamingDelegate>)automixIQStreamingDelegate
socialRadioStreamingDelegate:(nonnull id<SocialRadioStreamingDelegate>)socialRadioStreamingDelegate
  socialRadioStatusDelegate:(nullable id<SocialRadioStatusObserverDelegate>)socialRadioStatusDelegate
      socialRadioUIDelegate:(nonnull id<SocialRadioUIDelegate>)socialRadioUIDelegate
      socialBackendDelegate:(nonnull id<SocialBackendDelegate>)socialBackendDelegate
                 completion:(void (^_Nullable)(NSError* _Nullable error))completion;

+(BOOL)initialised;
+(nullable SocialRadioObjC*)instance;

-(void)forceRefreshCredentialsWithCompletion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)startRadioSessionWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                               metadata:(nullable NSArray<TunedTrackModel*>*)trackMetadataArray
                         playTrackIndex:(int)index seconds:(float)seconds autoplay:(BOOL)autoplay
                            contextType:(nullable NSString*)contextType contextId:(int)contextId
                             completion:(void (^_Nullable)(NSError* _Nullable error, UIViewController* _Nullable viewController))completion;
-(void)endRadioSessionWithCompletion:(void (^_Nonnull)(void))completion;

-(nonnull UIViewController*)radioUIViewController;

-(void)getLiveBroadcastsWithLimit:(int)limit
                            start:(nullable NSString*)start
                       completion:(void (^_Nullable)(NSError* _Nullable error, SocialRadioList* _Nullable liveMixtapes))completion;

-(void)reportUserWithIdentifier:(nonnull NSString*)identifier
                     completion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)reportMixtapeWithIdentifier:(nonnull NSString*)identifier
                        completion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)notifyFollowersWithUserIdentifier:(nonnull NSString*)identifier
                                   title:(nonnull NSString*)title
                                    body:(nonnull NSString*)body
                              objectType:(nonnull NSString*)objectType
                                objectId:(nonnull NSString*)objectId
                              completion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)joinLiveBroadcastWithIdentifier:(nonnull NSString*)identifier
                            completion:(void (^_Nullable)(NSError* _Nullable error, UIViewController* _Nullable viewController))completion;

-(void)stopEngine;
-(void)setRecordingAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer;
-(int)getAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels fadeState:(int)fadeState audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer isRecording:(nonnull BOOL*)isRecording;
-(BOOL)isAudioDeviceActiveOrRecording:(nonnull BOOL*)recording;
-(void)playWithCompletion:(void (^_Nullable)(NSError* _Nullable error))completion;
-(void)addStatusObserverDelegate:(nonnull id<SocialRadioStatusObserverDelegate>)statusObserverDelegate;
-(void)removeStatusObserverDelegate:(nonnull id<SocialRadioStatusObserverDelegate>)statusObserverDelegate;

+(BOOL)internetAvailable;

-(void)clearCacheWithCompletion:(void (^_Nullable)(NSError* _Nullable error))completion;
-(void)terminate;
-(BOOL)on;
@end

#endif

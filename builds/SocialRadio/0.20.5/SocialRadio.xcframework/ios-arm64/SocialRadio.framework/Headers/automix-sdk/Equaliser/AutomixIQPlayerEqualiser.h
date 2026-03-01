
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

/// A 3-band equaliser you can use with AVPlayer and AutomixIQ
@interface AutomixIQPlayerEqualiser : NSObject

/// Set the cutoff frequencies of the filters (default to 300Hz and 3300Hz, use the equaliser after setting them to apply)
+(void)setLowCutoffFrequencyHz:(float)lowCutoffFrequencyHz;
+(void)setHighCutoffFrequencyHz:(float)highCutoffFrequencyHz;

/// Enable/disable EQ processing. When disabled, audio passes through unchanged.
@property (atomic, assign, getter=isEnabled) BOOL enabled;

/// Create an instance. Initially enabled with 0 dB preamp and band gains.
-(nonnull instancetype)init;

/// Attach to an AVPlayer. The equalizer automatically (re)attaches to
/// the player's currentItem when it becomes ready, and when it changes.
/// Returns YES if observation is set; it may attach asynchronously later
/// when the item becomes ready. Returns NO only if the player is nil.
-(BOOL)attachToPlayer:(nonnull AVPlayer *)player;

/// Stop observing the player and detach any active tap.
-(void)detachFromPlayer;

/// Set individual EQ gains in dB (Low, Mid, High). Defaults 0 dB each.
-(void)setLowGainDB:(float)db;
-(void)setMidGainDB:(float)db;
-(void)setHighGainDB:(float)db;

/// get individual EQ gains in dB (Low, Mid, High). Defaults 0 dB each.
-(float)getLowGainDB:(float)db;
-(float)getMidGainDB:(float)db;
-(float)getHighGainDB:(float)db;

/// Set the values of the equaliser to AutomixIQ if initialised
-(void)applyToAutomix;

/// A convenient controls view with four sliders: Low, Mid, High.
/// You can embed this view in your UI. Sliders update the equalizer in realtime.
-(nullable UIView*)controlView;

/// Creates a convenient controls view with four sliders: Low, Mid, High.
/// You can embed this view in your UI. Sliders update the equalizer in realtime.
-(nonnull UIView*)createControlViewWithTextColor:(nullable UIColor*)textColor
                                        textFont:(nullable UIFont*)font
                                 switchTintColor:(nullable UIColor*)switchTintColor
                                 sliderTintColor:(nullable UIColor*)sliderTintColor
                               normalSliderImage:(nullable UIImage*)normalSliderImage
                          highlightedSliderImage:(nullable UIImage*)highlightedSliderImage
                                 backgroundColor:(nullable UIColor*)backgroundColor;

/// Computes minimum height using provided font, with fixed row spacing and minimum slider height
/// to avoid variability if UISlider renders thinner. Uses defaults when passing nil font.
-(float)minimumEqualiserHeightWithTextFont:(nullable UIFont*)font;

/// Returns the audio tap callbacks so they can be used in any other player
-(MTAudioProcessingTapCallbacks)audioProcessingTapCallbacks;

@end

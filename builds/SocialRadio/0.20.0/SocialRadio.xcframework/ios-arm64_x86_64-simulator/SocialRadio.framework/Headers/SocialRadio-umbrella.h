#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "radio-sdk/SocialRadioObjC.h"
#ifdef HAVE_AUTOMIXIQ
#import "automix-sdk/AutomixIQ.h"
#endif
#import "automix-sdk/CoreDataModels/_AutomixIQPlayLog.h"
#import "automix-sdk/CoreDataModels/AutomixIQPlayLog.h"
#import "automix-sdk/CoreDataModels/_AutomixIQTransitionLog.h"
#import "automix-sdk/CoreDataModels/AutomixIQTransitionLog.h"
#import "automix-sdk/MDMCoreDataWrapper.h"
#import "automix-sdk/Equaliser/AutomixIQPlayerEqualiser.h"

FOUNDATION_EXPORT double SocialRadioVersionNumber;
FOUNDATION_EXPORT const unsigned char SocialRadioVersionString[];

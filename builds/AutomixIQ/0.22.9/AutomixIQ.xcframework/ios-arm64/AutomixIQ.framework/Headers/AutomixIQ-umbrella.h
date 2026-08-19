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

#import "automix-sdk/AutomixIQ.h"
#import "automix-sdk/CoreDataModels/_AutomixIQPlayLog.h"
#import "automix-sdk/CoreDataModels/AutomixIQPlayLog.h"
#import "automix-sdk/CoreDataModels/_AutomixIQTransitionLog.h"
#import "automix-sdk/CoreDataModels/AutomixIQTransitionLog.h"
#import "automix-sdk/MDMCoreDataWrapper.h"
#import "automix-sdk/Equaliser/AutomixIQPlayerEqualiser.h"

FOUNDATION_EXPORT double AutomixIQVersionNumber;
FOUNDATION_EXPORT const unsigned char AutomixIQVersionString[];

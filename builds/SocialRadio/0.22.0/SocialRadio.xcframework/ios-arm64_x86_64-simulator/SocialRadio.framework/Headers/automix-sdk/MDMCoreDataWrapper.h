
#if !defined MDMCOREDATAWRAPPER_H
#define MDMCOREDATAWRAPPER_H


@class AutomixIQPlayLog;
@class AutomixIQTransitionLog;
@class MDMPersistenceController;
@class NSFetchRequest;


@interface _MDMCoreDataWrapper: NSObject

-(nonnull instancetype)initWithStoreURL:(nonnull NSURL*)storeURL model:(nonnull NSManagedObjectModel*)model;
-(void)saveContextAndWait:(BOOL)wait completion:(nullable void (^)(NSError* _Nullable error))completion;

// Play logs
-(nullable AutomixIQPlayLog*)insertNewPlayLog;
-(nonnull NSString*)playLogMDMCoreDataAdditionsEntityName;
-(void)deletePlayLog:(nonnull AutomixIQPlayLog*)playlog;

// Transition logs
-(nullable AutomixIQTransitionLog*)insertNewTransitionLog;
-(nonnull NSString*)transitionLogMDMCoreDataAdditionsEntityName;
-(void)deleteTransitionLog:(nonnull AutomixIQTransitionLog*)transitionlog;

// Requests
-(nullable NSArray*)executeFetchRequest:(nonnull NSFetchRequest*)request error:(nullable void (^)(NSError* _Nullable error))errorBlock;


@property (nonatomic, strong, nullable) MDMPersistenceController* persistanceController;

@end


#endif

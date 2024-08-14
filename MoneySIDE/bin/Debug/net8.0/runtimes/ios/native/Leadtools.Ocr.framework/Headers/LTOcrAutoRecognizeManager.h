// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrAutoRecognizeManager.h
//  Leadtools.Ocr
//

#import <Leadtools.Document.Writer/LTDocumentFormat.h>

#import <Leadtools.Ocr/LTOcrAutoRecognizeJobOperationEventArgs.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeJob.h>
#import <Leadtools.Ocr/LTOcrProgressData.h>

typedef NS_ENUM(NSInteger, LTOcrAutoRecognizeManagerJobErrorMode) {
    LTOcrAutoRecognizeManagerJobErrorModeAbort,
    LTOcrAutoRecognizeManagerJobErrorModeContinue
};

NS_ASSUME_NONNULL_BEGIN

@class LTOcrAutoRecognizeManager;
@protocol LTOcrAutoRecognizeManagerDelegate <NSObject>

@optional
- (void)autoRecognizeManager:(LTOcrAutoRecognizeManager *)manager progress:(LTOcrProgressData *)progressData;
- (void)autoRecognizeManager:(LTOcrAutoRecognizeManager *)manager didStartWithStatus:(LTOcrAutoRecognizeManagerJobStatus *)status;
- (void)autoRecognizeManager:(LTOcrAutoRecognizeManager *)manager didCompleteWithStatus:(LTOcrAutoRecognizeManagerJobStatus *)status;
- (void)autoRecognizeManager:(LTOcrAutoRecognizeManager *)manager willRunOperation:(LTOcrAutoRecognizeJobOperationEventArgs *)operation;
- (void)autoRecognizeManager:(LTOcrAutoRecognizeManager *)manager didRunOperation:(LTOcrAutoRecognizeJobOperationEventArgs *)operation;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrAutoRecognizeManager : NSObject

@property (nonatomic, weak, nullable)   id<LTOcrAutoRecognizeManagerDelegate> delegate;

@property (nonatomic, assign)           NSInteger maximumPagesBeforeLtd;
@property (nonatomic, assign)           NSInteger maximumThreadsPerJob;

@property (nonatomic, assign)           BOOL enableTrace;
@property (nonatomic, assign, readonly) BOOL isMultiThreadedSupported;

@property (nonatomic, assign)           LTOcrAutoRecognizeManagerJobErrorMode jobErrorMode;

@property (nonatomic, strong, readonly) NSMutableArray<NSNumber *> *preprocessPageCommands; // LTOcrAutoPreprocessPageCommand

- (instancetype)init __unavailable;

- (BOOL)run:(NSString *)imageFileName documentFileName:(NSString *)documentFileName zonesFileName:(nullable NSString *)zonesFileName format:(LTDocumentFormat)format error:(NSError **)error NS_SWIFT_NAME(run(imageFileName:documentFileName:zonesFileName:format:));

- (nullable LTOcrAutoRecognizeJob *)createJob:(LTOcrAutoRecognizeJobData *)jobData error:(NSError **)error NS_SWIFT_NAME(createJob(jobData:));

- (LTOcrAutoRecognizeManagerJobStatus)runJob:(LTOcrAutoRecognizeJob *)job error:(NSError **)error NS_SWIFT_NAME(run(_:));
- (BOOL)runJobAsync:(LTOcrAutoRecognizeJob *)job error:(NSError **)error NS_SWIFT_NAME(runAsync(_:));
- (void)abortAllJobs;

@end

NS_ASSUME_NONNULL_END

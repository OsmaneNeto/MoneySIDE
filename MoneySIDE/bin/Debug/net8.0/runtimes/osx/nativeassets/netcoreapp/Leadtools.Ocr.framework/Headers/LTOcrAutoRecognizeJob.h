// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrAutoRecognizeJob.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrAutoRecognizeJobData.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeManagerJobError.h>

NS_ASSUME_NONNULL_BEGIN

@class LTOcrAutoRecognizeManager;

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrAutoRecognizeJob : NSObject

@property (nonatomic, strong, readonly)           LTOcrAutoRecognizeManager *autoRecognizeManager;
@property (nonatomic, strong, readonly)           LTOcrAutoRecognizeJobData *jobData;
@property (nonatomic, strong, readonly, nullable) NSArray<LTOcrAutoRecognizeManagerJobError *> *errors;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

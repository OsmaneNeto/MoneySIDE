// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrStatistic.h
//  Leadtools.Ocr
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrStatistic : NSObject

@property (nonatomic, assign) NSUInteger recognizedCharacters;
@property (nonatomic, assign) NSUInteger recognizedWords;
@property (nonatomic, assign) NSUInteger rejectedCharacters;
@property (nonatomic, assign) NSUInteger correctedWords;

@property (nonatomic, assign) UInt64 recognitionTime;
@property (nonatomic, assign) UInt64 readingTime;
@property (nonatomic, assign) UInt64 imagePreprocessingTime;
@property (nonatomic, assign) UInt64 decompositionTime;

@end

NS_ASSUME_NONNULL_END

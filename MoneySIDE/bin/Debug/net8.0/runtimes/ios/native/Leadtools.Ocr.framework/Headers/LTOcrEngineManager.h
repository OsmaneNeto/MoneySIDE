// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrEngineManager.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrEngine.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrEngineManager : NSObject // STATIC CLASS

+ (LTOcrEngine *)createEngine:(LTOcrEngineType)engineType;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

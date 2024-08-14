// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMultiSauvolaBinarizeCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTMultiSauvolaBinarizeCommand : LTRasterCommand

@property (nonatomic, assign) double kFactor1;
@property (nonatomic, assign) double kFactor2;
@property (nonatomic, assign) NSInteger windowSize;
@property (nonatomic, assign) NSInteger rFactor;

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (void)getSauvolaImage:(LTRasterImage *)image index:(int)index;

@end

NS_ASSUME_NONNULL_END

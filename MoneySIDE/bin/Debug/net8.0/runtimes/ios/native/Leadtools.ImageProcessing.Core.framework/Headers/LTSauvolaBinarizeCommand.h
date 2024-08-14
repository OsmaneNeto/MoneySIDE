// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSauvolaBinarizeCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSauvolaBinarizeCommand : LTRasterCommand

@property (nonatomic, assign) double kFactor;
@property (nonatomic, assign) NSInteger windowSize;
@property (nonatomic, assign) NSInteger rFactor;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

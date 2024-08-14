// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSmoothEdgesCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSmoothEdgesCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger amount;
@property (nonatomic, assign) NSUInteger threshold;

- (instancetype)initWithAmount:(NSUInteger)amount threshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

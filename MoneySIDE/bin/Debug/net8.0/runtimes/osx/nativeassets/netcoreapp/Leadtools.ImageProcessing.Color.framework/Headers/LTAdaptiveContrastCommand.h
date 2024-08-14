// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAdaptiveContrastCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTAdaptiveContrastCommandType) {
    LTAdaptiveContrastCommandTypeExponential = 0x0001,
    LTAdaptiveContrastCommandTypeLinear      = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAdaptiveContrastCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger dimension;
@property (nonatomic, assign) NSUInteger amount;
@property (nonatomic, assign) LTAdaptiveContrastCommandType type;

- (instancetype)initWithDimension:(NSUInteger)dimension amount:(NSUInteger)amount type:(LTAdaptiveContrastCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

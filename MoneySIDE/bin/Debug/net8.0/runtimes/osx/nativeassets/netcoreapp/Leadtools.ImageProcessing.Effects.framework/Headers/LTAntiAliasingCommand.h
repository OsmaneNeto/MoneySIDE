// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAntiAliasingCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTAntiAliasingCommandType) {
    LTAntiAliasingCommandTypeType1,
    LTAntiAliasingCommandTypeType2,
    LTAntiAliasingCommandTypeType3,
    LTAntiAliasingCommandTypeDiagonal,
    LTAntiAliasingCommandTypeHorizontal,
    LTAntiAliasingCommandTypeVertical,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAntiAliasingCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, assign) NSUInteger dimension;
@property (nonatomic, assign) LTAntiAliasingCommandType filter;

- (instancetype)initWithThreshold:(NSInteger)threshold dimension:(NSUInteger)dimension filter:(LTAntiAliasingCommandType)filter NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

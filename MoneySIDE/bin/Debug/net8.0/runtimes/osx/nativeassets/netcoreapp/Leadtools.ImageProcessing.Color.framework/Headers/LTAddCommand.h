// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAddCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>

typedef NS_ENUM(NSInteger, LTAddCommandType) {
    LTAddCommandTypeAverage = 0x0001,
    LTAddCommandTypeAdd     = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAddCommand : LTRasterCommand

@property (nonatomic, assign)                     LTAddCommandType type;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;

- (instancetype)initWithType:(LTAddCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

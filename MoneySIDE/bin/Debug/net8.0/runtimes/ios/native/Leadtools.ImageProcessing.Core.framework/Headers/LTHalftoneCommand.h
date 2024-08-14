// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTHalftoneCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>

typedef NS_ENUM(NSInteger, LTHalfToneCommandType) {
    LTHalfToneCommandTypePrint       = 0x0000,
    LTHalfToneCommandTypeView        = 0x0001,
    LTHalfToneCommandTypeRectangular = 0x0002,
    LTHalfToneCommandTypeCircular    = 0x0003,
    LTHalfToneCommandTypeElliptical  = 0x0004,
    LTHalfToneCommandTypeRandom      = 0x0005,
    LTHalfToneCommandTypeLinear      = 0x0006,
    LTHalfToneCommandTypeUserDefined = 0x0007
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTHalftoneCommand : LTRasterCommand

@property (nonatomic, assign)           LTHalfToneCommandType type;
@property (nonatomic, assign)           NSInteger angle;
@property (nonatomic, assign)           NSUInteger dimension;
@property (nonatomic, strong, nullable) LTRasterImage *userDefinedImage;

- (instancetype)initWithType:(LTHalfToneCommandType)type angle:(NSInteger)angle dimension:(NSUInteger)dimension userDefinedImage:(nullable LTRasterImage *)userDefinedImage NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

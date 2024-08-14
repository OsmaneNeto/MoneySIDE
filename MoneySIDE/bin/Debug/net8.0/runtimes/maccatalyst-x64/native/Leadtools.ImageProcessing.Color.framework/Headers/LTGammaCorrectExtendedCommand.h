// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTGammaCorrectExtendedCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTGammaCorrectExtendedCommandType) {
    LTGammaCorrectExtendedCommandTypeRgbSpace = 0x0001,
    LTGammaCorrectExtendedCommandTypeYuvSpace = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTGammaCorrectExtendedCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger gamma;
@property (nonatomic, assign) LTGammaCorrectExtendedCommandType type;

- (instancetype)initWithGamma:(NSUInteger)gamma type:(LTGammaCorrectExtendedCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

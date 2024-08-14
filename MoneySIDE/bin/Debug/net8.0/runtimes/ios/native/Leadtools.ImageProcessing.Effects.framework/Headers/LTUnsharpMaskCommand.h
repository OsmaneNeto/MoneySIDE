// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTUnsharpMaskCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTUnsharpMaskCommandColorType) {
    LTUnsharpMaskCommandColorTypeNone = 0x0000,
    LTUnsharpMaskCommandColorTypeRgb  = 0x0001,
    LTUnsharpMaskCommandColorTypeYuv  = 0x0002,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTUnsharpMaskCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger amount;
@property (nonatomic, assign) NSInteger radius;
@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, assign) LTUnsharpMaskCommandColorType colorType;

- (instancetype)initWithAmount:(NSInteger)amount radius:(NSInteger)radius threshold:(NSInteger)threshold colorType:(LTUnsharpMaskCommandColorType)colorType NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

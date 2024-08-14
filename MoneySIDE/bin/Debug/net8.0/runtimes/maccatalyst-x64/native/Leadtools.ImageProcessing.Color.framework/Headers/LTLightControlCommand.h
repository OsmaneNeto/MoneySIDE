// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLightControlCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTLightControlCommandType) {
    LTLightControlCommandTypeRgb  = 0x0001,
    LTLightControlCommandTypeYuv  = 0x0002,
    LTLightControlCommandTypeGray = 0x0004,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLightControlCommand : LTRasterCommand

@property (nonatomic, strong, nullable) NSArray<NSNumber *> *lowerAverage;
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *average;
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *upperAverage;

@property (nonatomic, assign) LTLightControlCommandType type;

- (instancetype)initWithLowerAverage:(nullable NSArray<NSNumber *> *)lowerAverage average:(nullable NSArray<NSNumber *> *)average upperAverage:(nullable NSArray<NSNumber *> *)upperAverage type:(LTLightControlCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

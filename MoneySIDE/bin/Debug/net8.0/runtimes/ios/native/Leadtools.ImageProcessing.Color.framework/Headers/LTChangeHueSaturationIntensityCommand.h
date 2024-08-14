// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTChangeHueSaturationIntensityCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTChangeHueSaturationIntensityCommandData : NSObject

@property (nonatomic, assign) NSInteger hue;
@property (nonatomic, assign) NSInteger saturation;
@property (nonatomic, assign) NSInteger intensity;
@property (nonatomic, assign) NSInteger outerLow;
@property (nonatomic, assign) NSInteger outerHigh;
@property (nonatomic, assign) NSInteger innerLow;
@property (nonatomic, assign) NSInteger innerHigh;

- (instancetype)initWithHue:(NSInteger)hue saturation:(NSInteger)saturation intensity:(NSInteger)intensity outerLow:(NSInteger)outerLow outerHigh:(NSInteger)outerHigh innerLow:(NSInteger)innerLow innerHigh:(NSInteger)innerHigh NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTChangeHueSaturationIntensityCommand : LTRasterCommand

- (instancetype)initWithHue:(NSInteger)hue saturation:(NSInteger)saturation intensity:(NSInteger)intensity data:(NSArray<LTChangeHueSaturationIntensityCommandData *> *)data NS_DESIGNATED_INITIALIZER;

@property (nonatomic, assign) NSInteger hue;
@property (nonatomic, assign) NSInteger saturation;
@property (nonatomic, assign) NSInteger intensity;

@property (nonatomic, strong) NSMutableArray<LTChangeHueSaturationIntensityCommandData *> *data;

@end

NS_ASSUME_NONNULL_END

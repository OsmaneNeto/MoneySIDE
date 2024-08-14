// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorIntensityBalanceCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorIntensityBalanceCommandData : NSObject

@property (nonatomic, assign) NSInteger red;
@property (nonatomic, assign) NSInteger green;
@property (nonatomic, assign) NSInteger blue;

- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorIntensityBalanceCommand : LTRasterCommand

- (instancetype)initWithShadows:(LTColorIntensityBalanceCommandData *)shadows midTone:(LTColorIntensityBalanceCommandData *)midTone highLight:(LTColorIntensityBalanceCommandData *)highlight luminance:(BOOL)luminance NS_DESIGNATED_INITIALIZER;

@property (nonatomic, assign) BOOL luminance;
@property (nonatomic, strong) LTColorIntensityBalanceCommandData *shadows;
@property (nonatomic, strong) LTColorIntensityBalanceCommandData *midTone;
@property (nonatomic, strong) LTColorIntensityBalanceCommandData *highlight;

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBalanceColorsCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBalanceColorCommandFactor : NSObject

@property (nonatomic, assign) double red;
@property (nonatomic, assign) double green;
@property (nonatomic, assign) double blue;

- (instancetype)initWithRed:(double)red green:(double)green blue:(double)blue NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBalanceColorsCommand : LTRasterCommand

@property (nonatomic, strong) LTBalanceColorCommandFactor *redFactor;
@property (nonatomic, strong) LTBalanceColorCommandFactor *greenFactor;
@property (nonatomic, strong) LTBalanceColorCommandFactor *blueFactor;

- (instancetype)initWithRedFactor:(LTBalanceColorCommandFactor *)redFactor greenFactor:(LTBalanceColorCommandFactor *)greenFactor blueFactor:(LTBalanceColorCommandFactor *)blueFactor NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

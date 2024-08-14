// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTChannelMixerCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTChannelMixerCommandFactor : NSObject

@property (nonatomic, assign) NSInteger red;
@property (nonatomic, assign) NSInteger green;
@property (nonatomic, assign) NSInteger blue;
@property (nonatomic, assign) NSInteger constant;

- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue constant:(NSInteger)constant NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTChannelMixerCommand : LTRasterCommand

@property (nonatomic, strong) LTChannelMixerCommandFactor *redFactor;
@property (nonatomic, strong) LTChannelMixerCommandFactor *greenFactor;
@property (nonatomic, strong) LTChannelMixerCommandFactor *blueFactor;

- (instancetype)initWithRedFactor:(LTChannelMixerCommandFactor *)redFactor greenFactor:(LTChannelMixerCommandFactor *)greenFactor blueFactor:(LTChannelMixerCommandFactor *)blueFactor NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

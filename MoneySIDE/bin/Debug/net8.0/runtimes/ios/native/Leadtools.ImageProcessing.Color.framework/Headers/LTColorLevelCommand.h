// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorLevelCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTColorLevelCommandFlags) {
    LTColorLevelCommandFlagsNone   = 0x0000,
    LTColorLevelCommandFlagsRed    = 0x00000001,
    LTColorLevelCommandFlagsGreen  = 0x00000010,
    LTColorLevelCommandFlagsBlue   = 0x00000100,
    LTColorLevelCommandFlagsMaster = 0x00001000,
    LTColorLevelCommandFlagsAll    = 0x00001000 | 0x00000001 | 0x00000010 | 0x00000100,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorLevelCommandData : NSObject

@property (nonatomic, assign) NSInteger minimumInput;
@property (nonatomic, assign) NSInteger maximumInput;
@property (nonatomic, assign) NSInteger minimumOutput;
@property (nonatomic, assign) NSInteger maximumOutput;
@property (nonatomic, assign) NSUInteger gamma;

- (instancetype)initWithMinimumInput:(NSInteger)minimumInput maximumInput:(NSInteger)maximumInput minimumOutput:(NSInteger)minimumOutput maximumOutput:(NSInteger)maximumOutput gamma:(NSUInteger)gamma NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorLevelCommand : LTRasterCommand

@property (nonatomic, strong) LTColorLevelCommandData *master;
@property (nonatomic, strong) LTColorLevelCommandData *red;
@property (nonatomic, strong) LTColorLevelCommandData *green;
@property (nonatomic, strong) LTColorLevelCommandData *blue;
@property (nonatomic, assign) LTColorLevelCommandFlags flags;

- (id)initWithFlags:(LTColorLevelCommandFlags)flags;
- (id)initWithMaster:(LTColorLevelCommandData *)master red:(LTColorLevelCommandData *)red green:(LTColorLevelCommandData *)green blue:(LTColorLevelCommandData *)blue flags:(LTColorLevelCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

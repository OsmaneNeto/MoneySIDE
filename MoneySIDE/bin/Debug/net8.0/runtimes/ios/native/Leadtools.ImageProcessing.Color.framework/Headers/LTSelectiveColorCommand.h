// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSelectiveColorCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTSelectiveCommandColorTypes) {
    LTSelectiveCommandColorTypesRed     = 0x00000000,
    LTSelectiveCommandColorTypesYellow  = 0x00000001,
    LTSelectiveCommandColorTypesGreen   = 0x00000002,
    LTSelectiveCommandColorTypesCyan    = 0x00000003,
    LTSelectiveCommandColorTypesBlue    = 0x00000004,
    LTSelectiveCommandColorTypesMagenta = 0x00000005,
    LTSelectiveCommandColorTypesWhite   = 0x00000006,
    LTSelectiveCommandColorTypesNeutral = 0x00000007,
    LTSelectiveCommandColorTypesBlack   = 0x00000008,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSelectiveColorCommandData : NSObject <NSCopying>

@property (nonatomic, assign) int8_t cyan;
@property (nonatomic, assign) int8_t magenta;
@property (nonatomic, assign) int8_t yellow;
@property (nonatomic, assign) int8_t black;

- (instancetype)initWithCyan:(int8_t)cyan magenta:(int8_t)magenta yellow:(int8_t)yellow black:(int8_t)black NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSelectiveColorCommand : LTRasterCommand

@property (nonatomic, copy, null_unspecified) NSArray<LTSelectiveColorCommandData *> *colorsData;

- (instancetype)initWithColorsData:(NSArray<LTSelectiveColorCommandData *> *)colorsData NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

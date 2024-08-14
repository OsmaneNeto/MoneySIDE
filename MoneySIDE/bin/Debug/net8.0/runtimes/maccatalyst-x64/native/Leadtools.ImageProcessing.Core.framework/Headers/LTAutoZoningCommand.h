// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAutoZoningCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTLeadZoneType) {
    LTLeadZoneTypeText    = 0,
    LTLeadZoneTypeGraphic = 1,
    LTLeadZoneTypeTable   = 2,
};

typedef NS_ENUM(NSInteger, LTDitheringType) {
    LTDitheringTypeUndithered  = 0,
    LTDitheringTypeTextDither  = 1,
    LTDitheringTypeWhiteDither = 2
};

typedef NS_ENUM(NSInteger, LTDotMatrixType) {
    LTDotMatrixTypeDotMatrix = 0,
    LTDotMatrixTypeNone = 1,
};

typedef NS_OPTIONS(NSUInteger, LTAutoZoningOptions) {
    LTAutoZoningOptionsNone                             = 0,
    LTAutoZoningOptionsDetectText                       = 0x000001,
    LTAutoZoningOptionsDetectGraphics                   = 0x000002,
    LTAutoZoningOptionsDetectTable                      = 0x000004,
    LTAutoZoningOptionsDetectAll                        = 0x010007,
    LTAutoZoningOptionsAllowOverlap                     = 0x000010,
    LTAutoZoningOptionsDontAllowOverlap                 = 0x000000,
    LTAutoZoningOptionsDetectAccurateZones              = 0x000000,
    LTAutoZoningOptionsDetectGeneralZones               = 0x000100,
    LTAutoZoningOptionsDontRecognizeOneCellTable        = 0x000000,
    LTAutoZoningOptionsRecognizeOneCellTable            = 0x001000,
    LTAutoZoningOptionsUseMultiThreading                = 0x00000000,
    LTAutoZoningOptionsDontUseMultiThreading            = 0x80000000,
    LTAutoZoningOptionsUseNormalTableDetection          = 0x000000,
    LTAutoZoningOptionsUseAdvancedTableDetection        = 0x002000,
    LTAutoZoningOptionsUseTextDetectionVersion          = 0x008000,
    LTAutoZoningOptionsUseLinesReconstruction           = 0x004000,
    LTAutoZoningOptionsAsianAutoZone                    = 0x000200,
    LTAutoZoningOptionsDetectCheckbox                   = 0x010000,
    LTAutoZoningOptionsVerticalText                     = 0x100000,
    LTAutoZoningOptionsFavorGraphics                    = 0x400000,
    LTAutoZoningOptionsLowCheckboxDetectionSensitivity  = 0x000000,
    LTAutoZoningOptionsHighCheckboxDetectionSensitivity = 0x020000,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadZoneTableData : NSObject

@property (nonatomic, strong, readonly) NSMutableArray<NSNumber *> *cellTypes;
@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *cells; //LeadRect
@property (nonatomic, strong, readonly) NSMutableArray<NSArray<NSValue *> *> *insideCells; //LeadRect
@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *boundsToDraw; //LeadRect
@property (nonatomic, assign)           NSUInteger columns;
@property (nonatomic, assign)           NSUInteger rows;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadZoneTextData : NSObject

@property (nonatomic, strong, readonly) NSMutableArray<NSValue *> *textLines; //LeadRect

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadZone : NSObject

@property (nonatomic, assign) LTLeadZoneType type;
@property (nonatomic, assign) LeadRect bounds;
@property (nonatomic, strong) LTLeadZoneTableData *tableData;
@property (nonatomic, strong) LTLeadZoneTextData *textData;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAutoZoningCommand : LTRasterCommand

@property (nonatomic, assign, readonly)           LTDitheringType ditherType;
@property (nonatomic, assign, readonly)           LTDotMatrixType dotMatrix;
@property (nonatomic, strong, readonly)           NSMutableArray<LTLeadZone *> *zones;
@property (nonatomic, assign)                     LTAutoZoningOptions options;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *tableImage;

@property (nonatomic, assign, readonly, nullable) LeadRect *underlines;
@property (nonatomic, assign, readonly, nullable) LeadRect *checkboxes;
@property (nonatomic, assign, readonly, nullable) LeadRect *strikelines;

@property (nonatomic, assign, readonly)           NSUInteger underlinesCount;
@property (nonatomic, assign, readonly)           NSUInteger checkboxesCount;
@property (nonatomic, assign, readonly)           NSUInteger strikelinesCount;

- (instancetype)initWithOptions:(LTAutoZoningOptions)options NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrZone.h
//  Leadtools.Ocr
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.Ocr/LTOcrLanguage.h>
#import <Leadtools.Ocr/LTOcrZoneType.h>

typedef NS_OPTIONS(NSUInteger, LTOcrZoneCharacterFilters) {
   LTOcrZoneCharacterFiltersNone           = 0,
   LTOcrZoneCharacterFiltersDigit          = 1 << 0,
   LTOcrZoneCharacterFiltersUppercase      = 1 << 1,   // for future use.
   LTOcrZoneCharacterFiltersLowercase      = 1 << 2,   // for future use.
   LTOcrZoneCharacterFiltersPunctuation    = 1 << 3,   // for future use.
   LTOcrZoneCharacterFiltersMiscellaneous  = 1 << 4,   // for future use.
   LTOcrZoneCharacterFiltersPlus           = 1 << 5,
   LTOcrZoneCharacterFiltersAll            = LTOcrZoneCharacterFiltersDigit | LTOcrZoneCharacterFiltersUppercase | LTOcrZoneCharacterFiltersLowercase | LTOcrZoneCharacterFiltersPunctuation | LTOcrZoneCharacterFiltersMiscellaneous,    // for future use.
   LTOcrZoneCharacterFiltersAlpha          = LTOcrZoneCharacterFiltersUppercase | LTOcrZoneCharacterFiltersLowercase,   // for future use.
   LTOcrZoneCharacterFiltersNumbers        = LTOcrZoneCharacterFiltersDigit | LTOcrZoneCharacterFiltersPlus,
};

typedef NS_ENUM(NSInteger, LTOcrTextDirection) {
   LTOcrTextDirectionLeftToRight,
   LTOcrTextDirectionRightToLeft,
   LTOcrTextDirectionTopToBottom,
   LTOcrTextDirectionBottomToTop
};

typedef NS_ENUM(NSInteger, LTOcrTextStyle) {
   LTOcrTextStyleNormal,  // Normal (flow text)
   LTOcrTextStyleHeader,  // In header section of the the page. Usually smaller font
   LTOcrTextStyleFooter,  // In footer section of the the page. Usually smaller font
   LTOcrTextStyleHeading, // Heading is a text by itself. You can use FontRatio to calculate the type of the heading (h1, h2, h3, etc)
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrZone : NSObject <NSCopying>

@property (nonatomic, assign)                NSUInteger zoneId;

@property (nonatomic, copy, nullable)        NSString *name;

@property (nonatomic, assign)                LeadRect bounds;

@property (nonatomic, assign)                LTOcrZoneType zoneType;

@property (nonatomic, assign)                LTOcrZoneCharacterFilters characterFilters;

@property (nonatomic, assign)                LTOcrLanguage language;

@property (nonatomic, assign)                BOOL isEngineZone;

@property (nonatomic, copy, null_resettable) LTRasterColor *foreColor;
@property (nonatomic, copy, null_resettable) LTRasterColor *backColor;

@property (nonatomic, assign)                LTRasterViewPerspective viewPerspective;
@property (nonatomic, assign)                LTOcrTextDirection textDirection;
@property (nonatomic, assign)                LTOcrTextStyle textStyle;

@property (nonatomic, assign)                CGFloat fontRatio;

@end

NS_ASSUME_NONNULL_END

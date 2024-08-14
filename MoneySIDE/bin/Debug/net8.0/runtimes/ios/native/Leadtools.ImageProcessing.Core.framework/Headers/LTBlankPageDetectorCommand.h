// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBlankPageDetectorCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTBlankPageDetectorCommandFlags) {
   LTBlankPageDetectorCommandFlagsNone                    = 0x00000000,
#if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsDetectEmptyPage        = 0x00000000,
#endif // #if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsDetectNoisyPage        = 0x00000001,
#if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsDontIgnoreBleedThrough = 0x00000000,
#endif // #if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsIgnoreBleedThrough     = 0x00000010,
#if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsDontDetectLinedPage    = 0x00000000,
#endif // #if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsDetectLinedPage        = 0x00000100,
#if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsDontUseActiveArea      = 0x00000000,
#endif // #if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsUseActiveArea          = 0x00001000,
    LTBlankPageDetectorCommandFlagsUseDefaultMargins      = 0x00000000,
#if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsUseUserMargins         = 0x00010000,
#endif // #if !defined(LEADTOOLS_V21_OR_LATER)
    LTBlankPageDetectorCommandFlagsUseAdvanced            = 0x00100000,
    LTBlankPageDetectorCommandFlagsUsePixels              = 0x00000000,
    LTBlankPageDetectorCommandFlagsUseInches              = 0x00400000,
    LTBlankPageDetectorCommandFlagsUseCentimeters         = 0x00800000,
    LTBlankPageDetectorCommandFlagsDetectTextOnly         = 0x01000000
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBlankPageDetectorCommand : LTRasterCommand

@property (nonatomic, assign, readonly) BOOL isBlank;
@property (nonatomic, assign, readonly) NSUInteger accuracy;
@property (nonatomic, assign)           NSUInteger sensitivity;
#if defined(LEADTOOLS_V21_OR_LATER)
@property(nonatomic, assign)            NSUInteger minimumTextSize;
#endif // #if defined(LEADTOOLS_V21_OR_LATER)
@property (nonatomic, assign)           NSUInteger leftMargin;
@property (nonatomic, assign)           NSUInteger topMargin;
@property (nonatomic, assign)           NSUInteger rightMargin;
@property (nonatomic, assign)           NSUInteger bottomMargin;
@property (nonatomic, assign)           LTBlankPageDetectorCommandFlags flags;

- (instancetype)initWithFlags:(LTBlankPageDetectorCommandFlags)flags leftMargin:(NSUInteger)leftMargin topMargin:(NSUInteger)topMargin rightMargin:(NSUInteger)rightMargin bottomMargin:(NSUInteger)bottomMargin NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

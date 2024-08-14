// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTHtmlDocumentOptions.h
//  Leadtools.Document.Writer
//

#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTLeadtools.h>

#import <Leadtools.Document.Writer/LTDocumentOptions.h>

typedef NS_ENUM(NSInteger, LTHtmlDocumentType) {
    LTHtmlDocumentTypeIE         LT_ENUM_DEPRECATED(20_0),
    LTHtmlDocumentTypeNetscape   LT_ENUM_DEPRECATED(20_0),
    LTHtmlDocumentTypeIENetscape LT_ENUM_DEPRECATED(20_0)
};

typedef NS_OPTIONS(NSUInteger, LTDocumentFontTypes) {
    LTDocumentFontTypeDefault   = 0x00,
    LTDocumentFontTypeWOFF1     = 0x01,
    LTDocumentFontTypeEOT       = 0x02,
    LTDocumentFontTypeTTF       = 0x04,
    LTDocumentFontTypeWOFF2     = 0x08
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTHtmlDocumentOptions : LTDocumentOptions <NSCopying, NSCoding>

@property (nonatomic, assign) LTHtmlDocumentType documentType LT_DEPRECATED(20_0); 
@property (nonatomic, assign) LTDocumentFontEmbedMode fontEmbedMode;

@property (nonatomic, strong) LTRasterColor *backgroundColor;

@property (nonatomic, assign) LTDocumentDropObjects dropObjects;

@property (nonatomic, assign) BOOL useBackgroundColor;
@property (nonatomic, assign) BOOL embedImages;
@property (nonatomic, assign) BOOL embedFonts;
@property (nonatomic, assign) BOOL embedCSS;

@property (nonatomic, assign) LTRasterImageFormat imageType;
@property (nonatomic, assign) LTDocumentFontTypes fontTypes;

@end

NS_ASSUME_NONNULL_END

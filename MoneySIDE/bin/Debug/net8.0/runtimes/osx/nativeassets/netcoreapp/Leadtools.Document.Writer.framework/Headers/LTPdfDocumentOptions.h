// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTPdfDocumentOptions.h
//  Leadtools.Document.Writer
//

#import <Leadtools.Document.Writer/LTDocumentOptions.h>

typedef NS_ENUM(NSInteger, LTPdfDocumentType) {
    LTPdfDocumentTypePdf,
    LTPdfDocumentTypePdfA,
    LTPdfDocumentTypePdf12,
    LTPdfDocumentTypePdf13,
    LTPdfDocumentTypePdf15,
    LTPdfDocumentTypePdf16
};

typedef NS_ENUM(NSInteger, LTPdfDocumentEncryptionMode) {
    LTPdfDocumentEncryptionModeRC40Bit,
    LTPdfDocumentEncryptionModeRC128Bit
};

typedef NS_ENUM(NSInteger, LTPdfDocumentPageModeType) {
    LTPdfDocumentPageModeTypePageOnly = 0,
    LTPdfDocumentPageModeTypeFullScreen = 3,
    LTPdfDocumentPageModeTypeBookmarksAndPage = 1,
    LTPdfDocumentPageModeTypeThumbnailAndPage = 2,
    LTPdfDocumentPageModeTypeLayerAndPage = 4,
    LTPdfDocumentPageModeTypeAttachmentsAndPage = 5
};

typedef NS_ENUM(NSInteger, LTPdfDocumentPageLayoutType) {
    LTPdfDocumentPageLayoutTypeSinglePageDisplay,
    LTPdfDocumentPageLayoutTypeOneColumnDisplay,
    LTPdfDocumentPageLayoutTypeTwoColumnLeftDisplay,
    LTPdfDocumentPageLayoutTypeTwoColumnRightDisplay,
    LTPdfDocumentPageLayoutTypeTwoPageLeft,
    LTPdfDocumentPageLayoutTypeTwoPageRight
};

typedef NS_ENUM(NSInteger, LTPdfDocumentPageFitType) {
    LTPdfDocumentPageFitTypeDefault,
    LTPdfDocumentPageFitTypeFitWidth,
    LTPdfDocumentPageFitTypeFitHeight,
    LTPdfDocumentPageFitTypeFitWidthBounds,
    LTPdfDocumentPageFitTypeFitHeightBounds,
    LTPdfDocumentPageFitTypeFitBounds
};



NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPdfAutoBookmark : NSObject <NSCopying, NSCoding>

@property (nonatomic, assign)         BOOL useStyles;
@property (nonatomic, assign)         BOOL boldStyle;
@property (nonatomic, assign)         BOOL italicStyle;

@property (nonatomic, assign)         double fontHeight;

@property (nonatomic, copy, nullable) NSString *fontFaceName;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPdfCustomBookmark : NSObject <NSCopying, NSCoding>

@property (nonatomic, assign)         NSInteger levelNumber;
@property (nonatomic, assign)         NSInteger pageNumber;

@property (nonatomic, assign)         double xCoordinate;
@property (nonatomic, assign)         double yCoordinate;

@property (nonatomic, copy, nullable) NSString *name;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPdfDocumentOptions : LTDocumentOptions <NSCopying, NSCoding>

@property (nonatomic, assign)           LTPdfDocumentType documentType;
@property (nonatomic, assign)           LTDocumentFontEmbedMode fontEmbedMode;
@property (nonatomic, assign)           LTPdfDocumentEncryptionMode encryptionMode;
@property (nonatomic, assign)           LTOneBitImageCompressionType oneBitImageCompression;
@property (nonatomic, assign)           LTColoredImageCompressionType coloredImageCompression;
@property (nonatomic, assign)           LTDocumentImageOverTextSize imageOverTextSize;
@property (nonatomic, assign)           LTDocumentImageOverTextMode imageOverTextMode;
@property (nonatomic, assign)           LTPdfDocumentPageModeType pageModeType;
@property (nonatomic, assign)           LTPdfDocumentPageLayoutType pageLayoutType;
@property (nonatomic, assign)           LTPdfDocumentPageFitType pageFitType;
@property (nonatomic, assign)           LTDocumentDropObjects dropObjects;

@property (nonatomic, assign)           NSInteger qualityFactor;
@property (nonatomic, assign)           NSInteger totalBookmarkLevels;
@property (nonatomic, assign)           NSInteger initialPageNumber;

@property (nonatomic, assign)           double xCoordinate;
@property (nonatomic, assign)           double yCoordinate;
@property (nonatomic, assign)           double zoomPercent;

@property (nonatomic, assign)           BOOL imageOverText;
@property (nonatomic, assign)           BOOL linearized;
@property (nonatomic, assign)           BOOL Protected;
@property (nonatomic, assign)           BOOL printEnabled;
@property (nonatomic, assign)           BOOL highQualityPrintEnabled;
@property (nonatomic, assign)           BOOL copyEnabled;
@property (nonatomic, assign)           BOOL editEnabled;
@property (nonatomic, assign)           BOOL annotationsEnabled;
@property (nonatomic, assign)           BOOL assemblyEnabled;
@property (nonatomic, assign)           BOOL autoBookmarksEnabled;
@property (nonatomic, assign)           BOOL hideToolbar;
@property (nonatomic, assign)           BOOL hideMenubar;
@property (nonatomic, assign)           BOOL hideWindowUI;
@property (nonatomic, assign)           BOOL fitWindow;
@property (nonatomic, assign)           BOOL centerWindow;
@property (nonatomic, assign)           BOOL displayDocTitle;

@property (nonatomic, copy, nullable)   NSString *title;
@property (nonatomic, copy, nullable)   NSString *subject;
@property (nonatomic, copy, nullable)   NSString *keywords;
@property (nonatomic, copy, nullable)   NSString *author;
@property (nonatomic, copy, nullable)   NSString *userPassword;
@property (nonatomic, copy, nullable)   NSString *ownerPassword;
@property (nonatomic, copy, nullable)   NSString *creator;
@property (nonatomic, copy, nullable)   NSString *producer;

@property (nonatomic, strong, nullable) NSArray<LTPdfAutoBookmark *> *autoBookmarks;
@property (nonatomic, strong, nullable) NSArray<LTPdfCustomBookmark *> *customBookmarks;

@end

NS_ASSUME_NONNULL_END

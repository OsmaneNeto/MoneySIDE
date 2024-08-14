// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrDocumentManager.h
//  Leadtools.Ocr
//

#import <Leadtools.Ocr/LTOcrLanguage.h>
#import <Leadtools.Ocr/LTOcrDocument.h>

@class LTOcrEngine;

typedef NS_ENUM(NSInteger, LTOcrDocumentFontType) {
   LTOcrDocumentFontTypeProportionalSerif = 0,
   LTOcrDocumentFontTypeProportionalSansSerif,
   LTOcrDocumentFontTypeFixedSerif,
   LTOcrDocumentFontTypeFixedSansSerif,
   LTOcrDocumentFontTypeMICR
};

typedef NS_OPTIONS(NSUInteger, LTOcrCreateDocumentOptions) {
   LTOcrCreateDocumentOptionsNone           = 0,
   LTOcrCreateDocumentOptionsInMemory       = 1 << 0,
   LTOcrCreateDocumentOptionsAutoDeleteFile = 1 << 1,
   LTOcrCreateDocumentOptionsLoadExisting   = 1 << 2
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrDocumentManager : NSObject

- (nullable LTOcrDocument *)createDocument:(nullable NSString *)ocrDocumentFilePath options:(LTOcrCreateDocumentOptions)options error:(NSError **)error NS_SWIFT_NAME(createDocument(filePath:options:));

- (nullable NSArray<NSString *> *)fontNamesForLanguage:(LTOcrLanguage)language error:(NSError **)error;
- (BOOL)setFontNames:(NSArray<NSString *> *)fontNames forLanguage:(LTOcrLanguage)language error:(NSError **)error;

- (nullable NSString *)fontNameForLanguage:(LTOcrLanguage)language fontType:(LTOcrDocumentFontType)fontType error:(NSError **)error;
- (void)setFontName:(NSString *)fontName forLanguage:(LTOcrLanguage)language fontType:(LTOcrDocumentFontType)fontType error:(NSError **)error;

@end



@interface LTOcrDocumentManager (Deprecated)

- (nullable LTOcrDocument *)createDocument:(nullable NSString *)ocrDocumentFilePath options:(LTOcrCreateDocumentOptions)options LT_DEPRECATED_USENEW(19_0, "createDocument:options:error:");

- (nullable NSArray*)getFontNames:(LTOcrLanguage)language error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "fontNamesForLanguage:error:");
- (BOOL)setFontNames:(LTOcrLanguage)language fontNames:(NSArray*)fontNames error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "setFontNames:forLanguage:error:");

- (nullable NSString*)getFontName:(LTOcrLanguage)language fontType:(LTOcrDocumentFontType)fontType LT_DEPRECATED_USENEW(19_0, "fontNameForLanguage:fontType:");
- (void)setFontName:(LTOcrLanguage)language fontType:(LTOcrDocumentFontType)fontType fontName:(NSString*)fontName LT_DEPRECATED_USENEW(19_0, "setFontName:forLanguage:fontType:");

@end

NS_ASSUME_NONNULL_END

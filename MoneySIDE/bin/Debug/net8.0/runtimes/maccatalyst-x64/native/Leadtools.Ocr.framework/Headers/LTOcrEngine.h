// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrEngine.h
//  Leadtools.Ocr
//

#import <Leadtools/LTRasterImage.h>
#import <Leadtools.Codecs/LTRasterCodecs.h>
#import <Leadtools.Document.Writer/LTDocumentWriter.h>

#import <Leadtools.Ocr/LTOcrEngineType.h>
#import <Leadtools.Ocr/LTOcrImageSharingMode.h>
#import <Leadtools.Ocr/LTOcrStatistic.h>
#import <Leadtools.Ocr/LTOcrPage.h>

#import <Leadtools.Ocr/LTOcrSettingManager.h>
#import <Leadtools.Ocr/LTOcrLanguageManager.h>
#import <Leadtools.Ocr/LTOcrSpellCheckManager.h>
#import <Leadtools.Ocr/LTOcrZoneManager.h>
#import <Leadtools.Ocr/LTOcrDocumentManager.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeManager.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrEngine : NSObject

@property (nonatomic, assign, readonly)           BOOL isStarted;

@property (nonatomic, assign, readonly)           LTOcrEngineType engineType;

@property (nonatomic, copy, readonly, nullable)   NSString *workDirectory;

@property (nonatomic, strong, readonly, nullable) LTOcrStatistic *lastStatistic;

@property (nonatomic, strong, readonly)           LTRasterCodecs *rasterCodecsInstance;
@property (nonatomic, strong, readonly)           LTDocumentWriter *documentWriterInstance;
@property (nonatomic, strong, readonly)           LTOcrSettingManager *settingManager;
@property (nonatomic, strong, readonly)           LTOcrLanguageManager *languageManager;
@property (nonatomic, strong, readonly)           LTOcrSpellCheckManager *spellCheckManager;
@property (nonatomic, strong, readonly)           LTOcrZoneManager *zoneManager;
@property (nonatomic, strong, readonly)           LTOcrDocumentManager *documentManager;
@property (nonatomic, strong, readonly)           LTOcrAutoRecognizeManager *autoRecognizeManager;

- (instancetype)init __unavailable;

- (BOOL)startup:(nullable LTRasterCodecs *)rasterCodecs documentWriter:(nullable LTDocumentWriter *)documentWriter workDirectory:(nullable NSString *)workDirectory engineDirectory:(nullable NSString *)engineDirectory error:(NSError **)error NS_SWIFT_NAME(startup(rasterCodecs:documentWriter:workDirectory:engineDirectory:));
- (BOOL)startup:(nullable LTRasterCodecs *)rasterCodecs workDirectory:(nullable NSString *)workDirectory startupParameters:(nullable NSString *)startupParameters error:(NSError **)error NS_SWIFT_NAME(startup(rasterCodecs:workDirectory:startupParameters:));

- (void)shutdown;

- (nullable LTOcrPage *)createPage:(LTRasterImage *)image sharingMode:(LTOcrImageSharingMode)sharingMode error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END

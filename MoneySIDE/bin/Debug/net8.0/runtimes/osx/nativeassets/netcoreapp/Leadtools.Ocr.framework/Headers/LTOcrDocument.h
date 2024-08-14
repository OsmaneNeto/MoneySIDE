// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrDocument.h
//  Leadtools.Ocr
//

#import <Leadtools/LTLeadStream.h>
#import <Leadtools.Codecs/LTRasterCodecs.h>
#import <Leadtools.Document.Writer/LTDocumentWriter.h>

#import <Leadtools.Ocr/LTOcrProgressData.h>
#import <Leadtools.Ocr/LTOcrPageCollection.h>
#import <Leadtools.Ocr/LTOcrWriteXmlOptions.h>

@class LTOcrEngine;

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrDocument : NSObject

@property (nonatomic, assign, readonly)           BOOL isInMemory;
@property (nonatomic, assign)                     BOOL useEngineInstanceOptions;

@property (nonatomic, strong, readonly)           LTRasterCodecs *rasterCodecsInstance;
@property (nonatomic, strong, readonly)           LTDocumentWriter *documentWriterInstance;
@property (nonatomic, strong, readonly)           LTOcrEngine *engine;
@property (nonatomic, strong, readonly)           LTOcrPageCollection *pages;

@property (nonatomic, strong, readonly, nullable) NSString *fileName;

- (BOOL)saveToStream:(LTLeadStream *)stream format:(LTDocumentFormat)format progress:(nullable LTOcrProgressHandler)progressHandler error:(NSError **)error NS_SWIFT_NAME(save(to:format:progress:));
- (BOOL)saveToFile:(NSString *)fileName format:(LTDocumentFormat)format progress:(nullable LTOcrProgressHandler)progressHandler error:(NSError **)error NS_SWIFT_NAME(save(to:format:progress:));
- (BOOL)saveToData:(NSMutableData *)data format:(LTDocumentFormat)format progress:(nullable LTOcrProgressHandler)progressHandler error:(NSError **)error NS_SWIFT_NAME(save(to:format:progress:));

- (BOOL)saveZonesToStream:(LTLeadStream *)stream xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error NS_SWIFT_NAME(saveZones(to:writeOptions:));
- (BOOL)saveZonesToFile:(NSString *)fileName xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error NS_SWIFT_NAME(saveZones(to:writeOptions:));
- (BOOL)saveZonesToData:(NSMutableData *)data xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error NS_SWIFT_NAME(saveZones(to:writeOptions:));

- (BOOL)loadZonesFromStream:(LTLeadStream *)stream error:(NSError **)error NS_SWIFT_NAME(loadZones(from:));
- (BOOL)loadZonesFromFile:(NSString *)fileName error:(NSError **)error NS_SWIFT_NAME(loadZones(from:));
- (BOOL)loadZonesFromData:(NSMutableData *)data error:(NSError **)error NS_SWIFT_NAME(loadZones(from:));

- (BOOL)saveXmlToStream:(LTLeadStream *)stream xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error NS_SWIFT_NAME(saveXml(to:writeOptions:outputOptions:));
- (BOOL)saveXmlToFileName:(NSString *)fileName xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error NS_SWIFT_NAME(saveXml(to:writeOptions:outputOptions:));
- (BOOL)saveXmlToData:(NSMutableData *)data xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error NS_SWIFT_NAME(saveXml(to:writeOptions:outputOptions:));

@end



@interface LTOcrDocument (Deprecated)

- (BOOL)save:(LTLeadStream *)stream target:(id)target selector:(SEL)selector error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "saveToStream:error:");

- (void)saveZones:(LTLeadStream *)stream xmlWriteOptions:(LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "saveZonesToStream:xmlWriteOptions:error:");
- (void)loadZones:(LTLeadStream *)stream error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "loadZonesFromStream:error:");

- (void)saveXml:(LTLeadStream *)stream xmlWriteOptions:(LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "saveXmlToStream:xmlWriteOptions:outputOptions:error:");

@end

NS_ASSUME_NONNULL_END

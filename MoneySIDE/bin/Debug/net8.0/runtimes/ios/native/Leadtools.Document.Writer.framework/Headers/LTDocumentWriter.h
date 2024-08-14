// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDocumentWriter.h
//  Leadtools.Document.Writer
//

#import <Leadtools.Document.Writer/LTDocumentOptions.h>
#import <Leadtools.Document.Writer/LTDocumentWriterPage.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLtdDocumentInfo : NSObject

@property (nonatomic, assign) NSInteger pageCount;
@property (nonatomic, assign) LTLtdDocumentType type;

@end

typedef void (^LTDocumentWriterProgressHandler)(NSInteger percentage, BOOL *stop) NS_SWIFT_NAME(LTDocumentWriter.ProgressHandler);


NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDocumentWriter : NSObject

@property (class, nonatomic, strong, readonly) NSArray<NSNumber *> *allSupportedFormats; // LTDocumentFormat

+ (NSString *)fileExtensionForFormat:(LTDocumentFormat)format;
+ (NSString *)friendlyNameForFormat:(LTDocumentFormat)format;

- (__kindof LTDocumentOptions *)optionsForFormat:(LTDocumentFormat)format;
- (void)setOptions:(nullable __kindof LTDocumentOptions *)options forFormat:(LTDocumentFormat)format;

- (BOOL)loadOptionsFromFile:(NSString *)fileName error:(NSError **)error NS_AVAILABLE_MAC(10_10) NS_SWIFT_NAME(loadOptions(from:));
- (BOOL)loadOptionsFromData:(NSData *)data error:(NSError **)error NS_AVAILABLE_MAC(10_10) NS_SWIFT_NAME(loadOptions(from:));
- (BOOL)saveOptionsToFile:(NSString *)fileName error:(NSError **)error NS_AVAILABLE_MAC(10_10) NS_SWIFT_NAME(saveOptions(to:));
- (void)saveOptionsToData:(NSMutableData *)data NS_AVAILABLE_MAC(10_10) NS_SWIFT_NAME(saveOptions(to:));

- (BOOL)beginDocumentWithFileName:(NSString *)fileName format:(LTDocumentFormat)format progress:(nullable LTDocumentWriterProgressHandler)progress error:(NSError **)error NS_SWIFT_NAME(beginDocument(fileName:format:progress:));
- (BOOL)endDocument:(nullable LTDocumentWriterProgressHandler)progressHandler error:(NSError **)error NS_SWIFT_NAME(endDocument(progress:));

- (BOOL)convertLtdFile:(NSString *)ltdFileName outputFile:(NSString *)outputFileName format:(LTDocumentFormat)format progress:(nullable LTDocumentWriterProgressHandler)progress error:(NSError **)error NS_SWIFT_NAME(convert(ltdFile:outputFile:format:progress:));

- (BOOL)addPage:(__kindof LTDocumentWriterPage *)page progress:(nullable LTDocumentWriterProgressHandler)progress error:(NSError **)error NS_SWIFT_NAME(add(_:progress:));
- (BOOL)insertPage:(__kindof LTDocumentWriterPage *)page progress:(nullable LTDocumentWriterProgressHandler)progress pageNumber:(NSUInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(insert(_:progress:pageNumber:));
- (BOOL)appendLtdFile:(NSString *)srcLtdFile destinationLtdFile:(NSString *)dstLtdFile error:(NSError **)error NS_SWIFT_NAME(append(ltdFile:destinationLtdFile:));
- (LTLtdDocumentInfo *)infoForLtdFile:(NSString *)fileName error:(NSError * _Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END

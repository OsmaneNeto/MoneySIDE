// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrAutoRecognizeJobOperationEventArgs.h
//  Leadtools.Ocr
//

#import <Leadtools/LTRasterImage.h>

#import <Leadtools.Document.Writer/LTDocumentWriter.h>
#import <Leadtools.Document.Writer/LTDocumentFormat.h>

#import <Leadtools.Ocr/LTOcrAutoRecognizeJob.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeManagerJobError.h>
#import <Leadtools.Ocr/LTOcrDocument.h>
#import <Leadtools.Ocr/LTOcrPage.h>

typedef NS_ENUM(NSInteger, LTOcrAutoRecognizeManagerJobStatus) {
    LTOcrAutoRecognizeManagerJobStatusSuccess,
    LTOcrAutoRecognizeManagerJobStatusAbort
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrAutoRecognizeJobOperationEventArgs : NSObject

@property (nonatomic, assign)                     LTOcrAutoRecognizeManagerJobStatus status;
@property (nonatomic, assign, readonly)           LTOcrAutoRecognizeManagerJobOperation operation;
@property (nonatomic, assign, readonly)           LTDocumentFormat format;

@property (nonatomic, assign, readonly)           NSInteger imagePageNumber;

@property (nonatomic, copy, readonly, nullable)   NSString *ltdFileName;
@property (nonatomic, copy, readonly, nullable)   NSString *documentFileName;

@property (nonatomic, strong, readonly)           LTOcrAutoRecognizeJob *job;
@property (nonatomic, strong, readonly, nullable) LTOcrDocument *document;
@property (nonatomic, strong, readonly, nullable) LTOcrPage *page;

@property (nonatomic, strong, nullable)           LTRasterImage *pageImage;

@property (nonatomic, strong, readonly, nullable) LTDocumentWriter *documentWriterInstance;

- (instancetype)initWithJob:(LTOcrAutoRecognizeJob *)job operation:(LTOcrAutoRecognizeManagerJobOperation)operation document:(nullable LTOcrDocument *)document page:(nullable LTOcrPage *)page imagePageNumber:(NSInteger)imagePageNumber ltdFileName:(nullable NSString *)ltdFileName format:(LTDocumentFormat)format documentFileName:(nullable NSString *)documentFileName documentWriter:(nullable LTDocumentWriter *)documentWriterInstance;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

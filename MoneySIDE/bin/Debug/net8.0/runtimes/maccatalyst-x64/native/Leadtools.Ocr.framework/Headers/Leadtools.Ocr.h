// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  Leadtools.Ocr.h
//  Leadtools.Ocr
//

#if !defined(LEADTOOLS_OCR_FRAMEWORK)
#define LEADTOOLS_OCR_FRAMEWORK

#import <Leadtools.Ocr/LTOcrDocument.h>
#import <Leadtools.Ocr/LTOcrDocumentManager.h>
#import <Leadtools.Ocr/LTOcrSpellCheckManager.h>
#import <Leadtools.Ocr/LTOcrLanguage.h>
#import <Leadtools.Ocr/LTOcrLanguageManager.h>
#import <Leadtools.Ocr/LTOcrSettingDescriptor.h>
#import <Leadtools.Ocr/LTOcrSettingManager.h>
#import <Leadtools.Ocr/LTOcrEngineType.h>
#import <Leadtools.Ocr/LTOcrEngine.h>
#import <Leadtools.Ocr/LTOcrEngineManager.h>
#import <Leadtools.Ocr/LTOcrMicrData.h>
#import <Leadtools.Ocr/LTOcrWriteXmlOptions.h>
#import <Leadtools.Ocr/LTOcrPage.h>
#import <Leadtools.Ocr/LTOcrProgressData.h>
#import <Leadtools.Ocr/LTOcrPageCollection.h>
#import <Leadtools.Ocr/LTOcrPageCharacters.h>
#import <Leadtools.Ocr/LTOcrZoneManager.h>
#import <Leadtools.Ocr/LTOcrOmrOptions.h>
#import <Leadtools.Ocr/LTOcrZoneType.h>
#import <Leadtools.Ocr/LTOcrZone.h>
#import <Leadtools.Ocr/LTOcrZoneCell.h>
#import <Leadtools.Ocr/LTOcrZoneCollection.h>
#import <Leadtools.Ocr/LTOcrZoneCharacters.h>
#import <Leadtools.Ocr/LTOcrImageSharingMode.h>
#import <Leadtools.Ocr/LTOcrAutoPreprocessPageCommand.h>
#import <Leadtools.Ocr/LTOcrCharacter.h>
#import <Leadtools.Ocr/LTOcrWord.h>
#import <Leadtools.Ocr/LTOcrMicrData.h>
#import <Leadtools.Ocr/LTOcrStatistic.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeManagerJobError.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeJobOperationEventArgs.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeJobData.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeJob.h>
#import <Leadtools.Ocr/LTOcrAutoRecognizeManager.h>
#import <Leadtools.Ocr/LTOcrModuleType.h>

// Versioning
#import <Leadtools/LTLeadtools.h>

LEADTOOLS_EXPORT const unsigned char LeadtoolsOcrVersionString[];
LEADTOOLS_EXPORT const double LeadtoolsOcrVersionNumber;

#endif // #if !defined(LEADTOOLS_OCR_FRAMEWORK)

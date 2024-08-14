// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  Leadtools.ImageProcessing.Core.h
//  Leadtools.ImageProcessing.Core
//

#if !defined(LEADTOOLS_IMAGEPROCESSING_CORE_FRAMEWORK)
#define LEADTOOLS_IMAGEPROCESSING_CORE_FRAMEWORK

#import <Leadtools.ImageProcessing.Core/LTMedianCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMinimumCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDotRemoveCommand.h>
#import <Leadtools.ImageProcessing.Core/LTApplyLinearModalityLookupTableCommand.h>
#import <Leadtools.ImageProcessing.Core/LTApplyLinearVoiLookupTableCommand.h>
#import <Leadtools.ImageProcessing.Core/LTApplyTransformationParametersCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDicomLookupTableDescriptor.h>
#import <Leadtools.ImageProcessing.Core/LTApplyModalityLookupTableCommand.h>
#import <Leadtools.ImageProcessing.Core/LTApplyVoiLookupTableCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoBinarizeCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoCropCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoCropRectangleCommand.h>
#import <Leadtools.ImageProcessing.Core/LTBlankPageDetectorCommand.h>
#import <Leadtools.ImageProcessing.Core/LTBorderRemoveCommand.h>
#import <Leadtools.ImageProcessing.Core/LTColorizeGrayCommand.h>
#import <Leadtools.ImageProcessing.Core/LTConvertSignedToUnsignedCommand.h>
#import <Leadtools.ImageProcessing.Core/LTConvertUnsignedToSignedCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCorrelationCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCorrelationListCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDeskewCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDespeckleCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDigitalSubtractCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDiscreteFourierTransformCommand.h>
#import <Leadtools.ImageProcessing.Core/LTExtractObjectsCommand.h>
#import <Leadtools.ImageProcessing.Core/LTFastFourierTransformCommand.h>
#import <Leadtools.ImageProcessing.Core/LTFourierTransformInformation.h>
#import <Leadtools.ImageProcessing.Core/LTFourierTransformDisplayCommand.h>
#import <Leadtools.ImageProcessing.Core/LTGetLinearVoiLookupTableCommand.h>
#import <Leadtools.ImageProcessing.Core/LTInvertedPageCommand.h>
#import <Leadtools.ImageProcessing.Core/LTInvertedTextCommand.h>
#import <Leadtools.ImageProcessing.Core/LTHalftoneCommand.h>
#import <Leadtools.ImageProcessing.Core/LTHighQualityRotateCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMaximumCommand.h>
#import <Leadtools.ImageProcessing.Core/LTLineRemoveCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMinimumToZeroCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMinMaxBitsCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMinMaxValuesCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMultiscaleEnhancementCommand.h>
#import <Leadtools.ImageProcessing.Core/LTResizeInterpolateCommand.h>
#import <Leadtools.ImageProcessing.Core/LTShiftDataCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSmoothCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSubtractBackgroundCommand.h>
#import <Leadtools.ImageProcessing.Core/LTTissueEqualizeCommand.h>
#import <Leadtools.ImageProcessing.Core/LTWindowLevelCommand.h>
#import <Leadtools.ImageProcessing.Core/LTWindowLevelExtCommand.h>
#import <Leadtools.ImageProcessing.Core/LTZeroToNegativeCommand.h>
#import <Leadtools.ImageProcessing.Core/LTGetBackgroundColorCommand.h>
#import <Leadtools.ImageProcessing.Core/LTOmrCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoZoningCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCoreUtilities.h>
#import <Leadtools.ImageProcessing.Core/LTSearchRegistrationMarksCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMICRCodeDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMRZCodeDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTEnums.h>
#import <Leadtools.ImageProcessing.Core/LTManualPerspectiveDeskewCommand.h>
#import <Leadtools.ImageProcessing.Core/LTPerspectiveDeskewCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCLAHECommand.h>
#import <Leadtools.ImageProcessing.Core/LTKMeansCommand.h>
#import <Leadtools.ImageProcessing.Core/LTWatershedCommand.h>
#import <Leadtools.ImageProcessing.Core/LTOtsuThresholdCommand.h>
#import <Leadtools.ImageProcessing.Core/LTLambdaConnectednessCommand.h>
#import <Leadtools.ImageProcessing.Core/LTLevelsetCommand.h>
#import <Leadtools.ImageProcessing.Core/LTShrinkWrapCommand.h>
#import <Leadtools.ImageProcessing.Core/LTKeyStoneCommand.h>
#import <Leadtools.ImageProcessing.Core/LTBlurDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAlignImagesCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAnisotropicDiffusionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTIDCardAlignmentCommand.h>
#import <Leadtools.ImageProcessing.Core/LTUnWarpCommand.h>
#import <Leadtools.ImageProcessing.Core/LTExpandContentCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoPageSplitterCommand.h>
#import <Leadtools.ImageProcessing.Core/LTBezierPathCommand.h>
#import <Leadtools.ImageProcessing.Core/LTShadedAreaRemovalCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSauvolaBinarizeCommand.h>
#import <Leadtools.ImageProcessing.Core/LTMultiSauvolaBinarizeCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCheckEstimatedOmrValidityCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCheckReaderCleanerCommand.h>
#import <Leadtools.ImageProcessing.Core/LTBrightnessDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTBackGroundRemovalCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoSegmentCommand.h>
#import <Leadtools.ImageProcessing.Core/LTAutoPictureBinarizationCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCannyEdgeDetectorCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCleaningUpFormFieldCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCMC7CodeDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTCompareBitmapCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDetectNoisyZonesCommand.h>
#import <Leadtools.ImageProcessing.Core/LTDetectQRBarcodeCommand.h>
#import <Leadtools.ImageProcessing.Core/LTFastMagicWandCommand.h>
#import <Leadtools.ImageProcessing.Core/LTGlareDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTHalfTonePatternCommand.h>
#import <Leadtools.ImageProcessing.Core/LTPreDefinedFilterCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSegmentMatchingCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSelectDataCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSigmaCommand.h>
#import <Leadtools.ImageProcessing.Core/LTSignalToNoiseRatioCommand.h>
#import <Leadtools.ImageProcessing.Core/LTTextBlurDetectionCommand.h>
#import <Leadtools.ImageProcessing.Core/LTTransformRectCommand.h>

// Versioning
#import <Leadtools/LTLeadtools.h>

LEADTOOLS_EXPORT const unsigned char LeadtoolsImageProcessingCoreVersionString[];
LEADTOOLS_EXPORT const double LeadtoolsImageProcessingCoreVersionNumber;

#endif // #if !defined(LEADTOOLS_IMAGEPROCESSING_CORE_FRAMEWORK)

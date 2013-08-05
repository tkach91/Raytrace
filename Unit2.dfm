object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1047#1072#1074#1080#1089#1080#1084#1086#1089#1090#1100' '#1074#1088#1077#1084#1077#1085#1080' '#1088#1072#1073#1086#1090#1099' '#1086#1090' '#1075#1083#1091#1073#1080#1085#1099' '#1090#1088#1072#1089#1089#1080#1088#1086#1074#1082#1080
  ClientHeight = 346
  ClientWidth = 559
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 0
    Top = 0
    Width = 559
    Height = 346
    Title.Text.Strings = (
      'TChart')
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 8
    ExplicitWidth = 346
    ExplicitHeight = 551
    PrintMargins = (
      15
      20
      15
      20)
    object Series1: TLineSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
end

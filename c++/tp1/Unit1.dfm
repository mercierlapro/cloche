object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 433
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 304
    Top = 440
    Width = 209
    Height = 33
    Caption = 'Button1'
    TabOrder = 0
  end
  object Button2: TButton
    Left = 232
    Top = 40
    Width = 169
    Height = 25
    Caption = 'Acquisition temperature'
    TabOrder = 1
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 232
    Top = 80
    Width = 75
    Height = 25
    Caption = 'debut'
    TabOrder = 2
    Visible = False
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 326
    Top = 80
    Width = 75
    Height = 25
    Caption = 'fin'
    TabOrder = 3
    Visible = False
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 232
    Top = 120
    Width = 169
    Height = 33
    Caption = 'Affichage courbe'
    TabOrder = 4
    Visible = False
    OnClick = Button5Click
  end
  object Chart1: TChart
    Left = 129
    Top = 159
    Width = 400
    Height = 250
    Title.Text.Strings = (
      'TChart')
    TabOrder = 5
    Visible = False
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      19
      15
      19)
    ColorPaletteIndex = 13
    object Series2: TLineSeries
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Button6: TButton
    Left = 80
    Top = 124
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Edit1: TEdit
    Left = 80
    Top = 82
    Width = 121
    Height = 21
    TabOrder = 7
    Text = 'Edit1'
  end
  object FrequenceAcquisition: TEdit
    Left = 440
    Top = 42
    Width = 121
    Height = 21
    TabOrder = 8
    Text = 'FrequenceAcquisition'
    Visible = False
  end
  object Button7: TButton
    Left = 486
    Top = 69
    Width = 75
    Height = 25
    Caption = 'OK2'
    TabOrder = 9
    Visible = False
    OnClick = Button7Click
  end
  object MainMenu1: TMainMenu
    object fichier1: TMenuItem
      Caption = 'fichier'
      object nouveau1: TMenuItem
        Caption = 'nouveau'
        OnClick = nouveau1Click
      end
      object fermer1: TMenuItem
        Caption = 'fermer'
        OnClick = fermer1Click
      end
    end
    object version1: TMenuItem
      Caption = 'version'
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 552
    Top = 168
  end
end

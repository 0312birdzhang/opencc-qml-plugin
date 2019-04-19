#include "opencc.h"
#include <QString>

#include <opencc/opencc.h>

OpenCC::OpenCC(QQuickItem *parent) : QQuickItem(parent) {
  const std::string mode_sTtw("s2twp.json");
  const std::string mode_twTs("tw2sp.json");
  converter_sTtw = new opencc::SimpleConverter(mode_sTtw);
  converter_twTs = new opencc::SimpleConverter(mode_twTs);
}

OpenCC::~OpenCC() { 
  delete converter_sTtw; 
  delete converter_twTs; 
}

QString OpenCC::convert(const QString qstr) const {
  // Use this if you ever wish to add Windows support
  // std::string str = qstr.toLocal8Bit().constData();
  std::string str = qstr.toUtf8().constData();
  std::string newStr = converter_sTtw->Convert(str);
  return QString(newStr.c_str());
}

QString OpenCC::convert2s(const QString qstr) const {
  std::string str = qstr.toUtf8().constData();
  std::string newStr = converter_twTs->Convert(str);
  return QString(newStr.c_str());
}
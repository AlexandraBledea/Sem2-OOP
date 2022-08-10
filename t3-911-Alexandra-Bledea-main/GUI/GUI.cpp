//
// Created by Alexandra on 5/24/2021.
//

#include "GUI.h"
#include "QVBoxLayout"
#include "QHBoxLayout"

GUI::GUI(Service &service): service{service} {
    this->init_GUI();
    this->populateList(this->service.getAll());
    this->connectSignalsAndSlots();
}

void GUI::init_GUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->overcastBox = new QCheckBox{};
    this->overcastBox->setText("overcast");
    this->overcastBox->setFont(buttonsFont);

    this->sunnyBox = new QCheckBox{};
    this->sunnyBox->setText("sunny");
    this->sunnyBox->setFont(buttonsFont);

    this->rainBox = new QCheckBox{};
    this->rainBox->setText("rain");
    this->rainBox->setFont(buttonsFont);

    this->thunderBox = new QCheckBox{};
    this->thunderBox->setText("thuderstorm");
    this->thunderBox->setFont(buttonsFont);

    this->foggyBox = new QCheckBox{};
    this->foggyBox->setText("foggy");
    this->foggyBox->setFont(buttonsFont);

    this->weatherListWidget = new QListWidget{};
    this->weatherListWidget->setFont(buttonsFont);

    this->spinner = new QSpinBox{};
    this->spinner->setFont(buttonsFont);
    this->spinner->setRange(0, 100);
    this->spinner->setValue(100);

    this->precipitationSlider = new QSlider(Qt::Orientation::Horizontal);
    this->precipitationSlider->setFont(buttonsFont);
    this->precipitationSlider->setMinimumHeight(50);
    this->precipitationSlider->setMinimumWidth(400);
    this->precipitationSlider->setRange(0, 100);
    this->precipitationSlider->setValue(100);

    QHBoxLayout* sliderLayout = new QHBoxLayout{};
    sliderLayout->addWidget(spinner);
    sliderLayout->addWidget(precipitationSlider);

    this->restoreButton = new QPushButton("Display all");
    this->restoreButton->setFont(buttonsFont);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(this->weatherListWidget);
    mainLayout->addLayout(sliderLayout);
    mainLayout->addWidget(this->restoreButton);
    mainLayout->addWidget(this->foggyBox);
    mainLayout->addWidget(this->thunderBox);
    mainLayout->addWidget(this->rainBox);
    mainLayout->addWidget(this->overcastBox);
    mainLayout->addWidget(this->sunnyBox);

    setLayout(mainLayout);

}

GUI::~GUI() {

}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->spinner, SIGNAL(valueChanged(int)), this->precipitationSlider, SLOT(setValue(int)));
    QObject::connect(this->precipitationSlider, &QSlider::valueChanged, this->spinner, &QSpinBox::setValue);
    QObject::connect(this->precipitationSlider, &QSlider::valueChanged, this, &GUI::filter);
    QObject::connect(this->restoreButton, &QPushButton::clicked, this, &GUI::displayAll);
//    QObject::connect(this->overcastBox, &QCheckBox::stateChanged, this, &GUI::filterByCheckBoxes);
//    QObject::connect(this->rainBox, &QCheckBox::stateChanged, this, &GUI::filterByCheckBoxes);
//    QObject::connect(this->sunnyBox, &QCheckBox::stateChanged, this, &GUI::filterByCheckBoxes);
//    QObject::connect(this->thunderBox, &QCheckBox::stateChanged, this, &GUI::filterByCheckBoxes);
//    QObject::connect(this->foggyBox, &QCheckBox::stateChanged, this, &GUI::filterByCheckBoxes);
    QObject::connect(this->overcastBox, &QCheckBox::stateChanged, this, &GUI::filter);
    QObject::connect(this->rainBox, &QCheckBox::stateChanged, this, &GUI::filter);
    QObject::connect(this->sunnyBox, &QCheckBox::stateChanged, this, &GUI::filter);
    QObject::connect(this->thunderBox, &QCheckBox::stateChanged, this, &GUI::filter);
    QObject::connect(this->foggyBox, &QCheckBox::stateChanged, this, &GUI::filter);
}

int GUI::getSelectedIndex() const {
    return 0;
}

void GUI::populateList(vector<weather> elements) {
    this->weatherListWidget->clear();
    for(auto & w: elements){
        this->weatherListWidget->addItem(QString::fromStdString(to_string(w.getStartHour()) + "-" + to_string(w.getEndHour()) + " | " + to_string(w.getPrecipitation())+ " | " + w.getDescription()));
    }
}

void GUI::filterByPrecipitation() {
    vector<weather> filtered = this->service.filterByPrecipitation(this->precipitationSlider->value());
    this->populateList(filtered);
}

void GUI::displayAll() {
    this->precipitationSlider->setValue(100);
    this->spinner->setValue(100);
    this->sunnyBox->setCheckState(static_cast<Qt::CheckState>(false));
    this->foggyBox->setCheckState(static_cast<Qt::CheckState>(false));
    this->rainBox->setCheckState(static_cast<Qt::CheckState>(false));
    this->thunderBox->setCheckState(static_cast<Qt::CheckState>(false));
    this->overcastBox->setCheckState(static_cast<Qt::CheckState>(false));
    this->populateList(this->service.getAll());
}

void GUI::filterByCheckBoxes() {
    vector<string> descriptions;
    if(this->sunnyBox->isChecked())
        descriptions.push_back("sunny");
    if(this->foggyBox->isChecked())
        descriptions.push_back("foggy");
    if(this->rainBox->isChecked())
        descriptions.push_back("rain");
    if(this->thunderBox->isChecked())
        descriptions.push_back("thunderstorm");
    if(this->overcastBox->isChecked())
        descriptions.push_back("overcast");

    vector<weather> filtered = this->service.filterByDescription(descriptions);
    this->populateList(filtered);
}

void GUI::filter() {
    vector<string> descriptions;
    if(this->sunnyBox->isChecked())
        descriptions.push_back("sunny");
    if(this->foggyBox->isChecked())
        descriptions.push_back("foggy");
    if(this->rainBox->isChecked())
        descriptions.push_back("rain");
    if(this->thunderBox->isChecked())
        descriptions.push_back("thunderstorm");
    if(this->overcastBox->isChecked())
        descriptions.push_back("overcast");
    if(descriptions.empty())
        this->filterByPrecipitation();
    else if(this->precipitationSlider->value() < 100){
        vector<weather> filtered = this->service.filterByPrecipitationAndDescription(this->precipitationSlider->value(), descriptions);
        this->populateList(filtered);
    }
    else if(this->precipitationSlider->value() == 100)
    {
        vector<weather> filtered = this->service.filterByDescription(descriptions);
        this->populateList(filtered);
    }
}


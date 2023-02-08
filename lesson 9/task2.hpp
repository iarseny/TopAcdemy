class SaveCalc : public Calc {

    private:
    std::string last_operation;

    public:
    SaveCalc() {}
    std::string getLastOperation() {
        return this->last_operation;
    }

    void plus(int a,int b) {
        this->Calc::plus(a,b);
        this->last_operation = "plus";
    }
    void minus(int a,int b) {
        this->Calc::minus(a,b);
        this->last_operation = "minus";
    }

    ~SaveCalc() {
        std::cout << std::endl << "Удалено !";
    }

};
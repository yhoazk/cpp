class Cow : public Animal {
    public:
    const char *see() const {
        return "cow";
    }

    const char *say() const {
        return "moo";
    }
};

class Pig : public Animal {
    public:
    const char *see() const {
        return "pig";
    }

    const char *say() const {
        return "oink";
    }
};

class Dog : public Animal {
    public:
    const char *see() const {
        return "cow";
    }

    const char *say() const {
        return "moo";
    }
};
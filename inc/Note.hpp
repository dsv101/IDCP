#ifndef IDCP_NOTE_HPP
#define IDCP_NOTE_HPP

#include <string>
#include <regex>

namespace idc
{
namespace parser
{
    class Note
    {
        public:
            enum Type
            {
                UNKNOWN,
                Q,
                T,
                C,
                L,
                R,
                
                QH,
                TH,
                CH,
                LH,
                RH,
                
                QHE,
                THE,
                CHE,
                LHE,
                RHE
            };
        
        private:
            static unsigned int numNotes;
            const std::regex exp = std::regex("^(q|t|c|l|r|qh|th|ch|lh|rh|qhe|the|che|lhe|rhe)(\\s+?((0)|((\\d+)[/](\\d+)))?)?$");
            Type type;
            float place;
            unsigned int uid;

        public:
            Note();
            Note(const Note &note);
            virtual ~Note();

            bool init(std::string line);

            Type get_type() const;
            float get_place() const;
            unsigned int get_uid() const;

            std::string to_string() const;
    };
}
}

#endif
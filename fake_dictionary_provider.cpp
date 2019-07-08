#include "fake_dictionary_provider.h"
#include "dictionary_item.h"
#include <QList>

FakeDictionaryProvider::FakeDictionaryProvider() {
  dictionary = std::shared_ptr<Dictionary>(new Dictionary);
  dictionary->append(
      DictionaryItem("fermion", "a particle with half-integer spin"));
  dictionary->append(DictionaryItem(
      "ferromagnet", "a magnet in which the microscopic magnetic moments "
                     "inside the material all point in the same direction"));
  dictionary->append(
      DictionaryItem("field", "a mathematical function that has a value (or "
                              "set of values) at all points in space"));
  dictionary->append(DictionaryItem(
      "flavor",
      "a set of quantum numbers that uniquely identify the type of particle"));
  dictionary->append(DictionaryItem(
      "frustrated", "a physical system with no well-defined ground state"));
  dictionary->append(DictionaryItem(
      "gluons",
      "particles in the Standard Model that mediate strong interactions"));
  dictionary->append(
      DictionaryItem("gravitino", "the superpartner of the graviton"));
  dictionary->append(DictionaryItem(
      "graviton", "postulated force carrier of the gravitational force"));
  dictionary->append(
      DictionaryItem("hadron", "Standard Model particle made of quarks"));
  dictionary->append(DictionaryItem(
      "inflation", "period of exponential expansion thought to have occurred "
                   "around 10-36 seconds after the universe began"));
  dictionary->append(DictionaryItem(
      "kaon", "any one of four mesons with nonzero strangeness"));
  dictionary->append(DictionaryItem("linac", "linear accelerator"));
}

std::shared_ptr<Dictionary> FakeDictionaryProvider::getDictionary() {
  return dictionary;
}

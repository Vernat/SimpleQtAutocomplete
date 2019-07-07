#include "fake_dictionary_provider.h"
#include "dictionary_item.h"
#include <QList>

FakeDictionaryProvider::FakeDictionaryProvider() {}

std::shared_ptr<Dictionary> FakeDictionaryProvider::getDictionary() {
  std::shared_ptr<Dictionary> dictionaryPtr(new Dictionary);
  dictionaryPtr->append(
      DictionaryItem("fermion", "a particle with half-integer spin"));
  dictionaryPtr->append(DictionaryItem(
      "ferromagnet", "a magnet in which the microscopic magnetic moments "
                     "inside the material all point in the same direction"));
  dictionaryPtr->append(
      DictionaryItem("field", "a mathematical function that has a value (or "
                              "set of values) at all points in space"));
  dictionaryPtr->append(DictionaryItem(
      "flavor",
      "a set of quantum numbers that uniquely identify the type of particle"));
  dictionaryPtr->append(DictionaryItem(
      "rustrated", "a physical system with no well-defined ground state"));
  dictionaryPtr->append(DictionaryItem(
      "gluons",
      "particles in the Standard Model that mediate strong interactions"));
  dictionaryPtr->append(
      DictionaryItem("gravitino", "the superpartner of the graviton"));
  dictionaryPtr->append(DictionaryItem(
      "graviton", "postulated force carrier of the gravitational force"));
  dictionaryPtr->append(
      DictionaryItem("hadron", "Standard Model particle made of quarks"));
  dictionaryPtr->append(DictionaryItem(
      "inflation", "period of exponential expansion thought to have occurred "
                   "around 10-36 seconds after the universe began"));
  dictionaryPtr->append(DictionaryItem(
      "kaon", "any one of four mesons with nonzero strangeness"));
  dictionaryPtr->append(DictionaryItem("linac", "linear accelerator"));

  return dictionaryPtr;
}
